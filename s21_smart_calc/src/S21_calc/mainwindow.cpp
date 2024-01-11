#include "mainwindow.h"
#include "ui_mainwindow.h"



MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    connect(ui->pushButton_0,SIGNAL(clicked()),this,SLOT(digits_numbers()));
    connect(ui->pushButton_1,SIGNAL(clicked()),this,SLOT(digits_numbers()));
    connect(ui->pushButton_2,SIGNAL(clicked()),this,SLOT(digits_numbers()));
    connect(ui->pushButton_3,SIGNAL(clicked()),this,SLOT(digits_numbers()));
    connect(ui->pushButton_4,SIGNAL(clicked()),this,SLOT(digits_numbers()));
    connect(ui->pushButton_5,SIGNAL(clicked()),this,SLOT(digits_numbers()));
    connect(ui->pushButton_6,SIGNAL(clicked()),this,SLOT(digits_numbers()));
    connect(ui->pushButton_7,SIGNAL(clicked()),this,SLOT(digits_numbers()));
    connect(ui->pushButton_8,SIGNAL(clicked()),this,SLOT(digits_numbers()));
    connect(ui->pushButton_9,SIGNAL(clicked()),this,SLOT(digits_numbers()));
     connect(ui->pushButton_dot,SIGNAL(clicked()),this,SLOT(digits_numbers()));
     connect(ui->pushButton_pow,SIGNAL(clicked()),this,SLOT(digits_numbers()));
     connect(ui->pushButton_multi,SIGNAL(clicked()),this,SLOT(digits_numbers()));
     connect(ui->pushButton_plus,SIGNAL(clicked()),this,SLOT(digits_numbers()));
     connect(ui->pushButton_minus,SIGNAL(clicked()),this,SLOT(digits_numbers()));
      connect(ui->pushButton_div,SIGNAL(clicked()),this,SLOT(digits_numbers()));
      connect(ui->pushButton_x,SIGNAL(clicked()),this,SLOT(digits_numbers()));
      connect(ui->pushButton_Lbr,SIGNAL(clicked()),this,SLOT(digits_numbers()));
      connect(ui->pushButton_Rbr,SIGNAL(clicked()),this,SLOT(digits_numbers()));

      connect(ui->pushButton_sqrt,SIGNAL(clicked()),this,SLOT(func_numbers()));
      connect(ui->pushButton_ln,SIGNAL(clicked()),this,SLOT(func_numbers()));
      connect(ui->pushButton_log,SIGNAL(clicked()),this,SLOT(func_numbers()));
      connect(ui->pushButton_tan,SIGNAL(clicked()),this,SLOT(func_numbers()));
      connect(ui->pushButton_atan,SIGNAL(clicked()),this,SLOT(func_numbers()));
      connect(ui->pushButton_acos,SIGNAL(clicked()),this,SLOT(func_numbers()));
      connect(ui->pushButton_cos,SIGNAL(clicked()),this,SLOT(func_numbers()));
      connect(ui->pushButton_asin,SIGNAL(clicked()),this,SLOT(func_numbers()));
      connect(ui->pushButton_sin,SIGNAL(clicked()),this,SLOT(func_numbers()));
      connect(ui->pushButton_mod,SIGNAL(clicked()),this,SLOT(func_numbers()));

    connect(ui->pushButton_eq,SIGNAL(clicked()),this,SLOT(res_numbers()));
    connect(ui->pushButton_AC,SIGNAL(clicked()),this,SLOT(AC_numbers()));
     connect(ui->pushButton_plot,SIGNAL(clicked()),this,SLOT(plot_numbers()));

}

MainWindow::~MainWindow()
{
    delete ui;
}
void MainWindow::plot_numbers(){
 ui->widget->clearGraphs();
QVector<double> x,y;


    h=0.1;
    double x1=ui->spinBox_x_min->text().toDouble();
    double x2=ui->spinBox_x_max->text().toDouble();
    double y1=ui->spinBox_y_min->text().toDouble();
    double y2=ui->spinBox_y_max->text().toDouble();
   N= (x1-x2)/h+2;
   X=x1;

   if(ui->input_x->text()!="") {
        double x_value = ui->input_x->text().toDouble();
        for(X=x1;X<=x2;X+=h){

 if(!validation( (ui->input->text()).toUtf8().data())) {
                    s21_node* tmp =s21_create_list();
                 if(!polish_notation( (ui->input->text()).toUtf8().data(),tmp,x_value)){
                          long double res=0;
                 if(!lexems_to_res(tmp,&res)){

                 x.push_back(X);
                         y.push_back((double)res);
}
                    };
}
}



   }
else{
       for(X=x1;X<=x2;X+=h){

               if(!validation( (ui->input->text()).toUtf8().data())) {
                   s21_node* tmp =s21_create_list();
                   if(!polish_notation( (ui->input->text()).toUtf8().data(),tmp,X)){
                         long double res=0;
                         if(!lexems_to_res(tmp,&res)){
                              x.push_back(X);
                             y.push_back((double)res);
                         };
                   };

               }


       }
   }

    ui->widget->xAxis->setRange( x1, x2);
     ui->widget->yAxis->setRange( y1, y2);
     ui->widget->addGraph();


     ui->widget->graph(0)->addData(x,y);

     ui->widget->replot();
}
 void MainWindow::digits_numbers()
 {

     QPushButton *button = ( QPushButton *)sender();

   if(ui->input_x->hasFocus()){
        ui->input_x->setText(ui->input_x->text()+button->text());
   }else  if(ui->input->hasFocus())
       ui->input->setText(ui->input->text()+button->text());


 }
 void MainWindow::func_numbers()
 {
      QPushButton *button = ( QPushButton *)sender();
   if(ui->input_x->hasFocus()){
         ui->input_x->setText(ui->input_x->text()+button->text()+'(');
    }else  if(ui->input->hasFocus())
       ui->input->setText(ui->input->text()+button->text()+'(');



 }

 void MainWindow::res_numbers()
 {


    bool flag=true;
    double x_value = ui->input_x->text().toDouble(&flag);
     if(strchr((ui->input->text()).toUtf8().data(),'x') && (ui->input_x->text()=="" || !flag)){
         ui->label_output->setText("ERROR!");
     }else {

         if(validation( (ui->input->text()).toUtf8().data())) ui->label_output->setText("ERROR!");
         else {
             s21_node* tmp =s21_create_list();
             if(!polish_notation( (ui->input->text()).toUtf8().data(),tmp,x_value)){
                   long double res=0;
                   if(!lexems_to_res(tmp,&res)){
                       QString out = QString::number(res,'g',7);
                     ui->label_output->setText(out);
                   }else  ui->label_output->setText("ERROR!");
             }else ui->label_output->setText("ERROR!");

         }

     }




 }

 void MainWindow::AC_numbers()
{
     if(ui->input_x->hasFocus()){
         QString buf =  ui->input_x->text();
         buf.chop(1);
         ui->input_x->setText(buf);
     }else  if(ui->input->hasFocus()){
         QString buf =  ui->input->text();
         buf.chop(1);
         ui->input->setText(buf);
  }
}


void MainWindow::on_pushButton_CE_clicked()
{
ui->input_x->setText("");
    ui->input->setText("");
    ui->label_output->setText("");
}






