#include "rational.h"
#include <numeric>
#include <cctype>
Rational::Rational(int num, int denum)
{
	if (denum == 0)
		throw DivisionByZeroError();

	this->num_ = num;
	this->denum_ = denum;
	this->reduce();
	return;
}

	Rational& Rational::operator+=(const Rational& rhs)
	{
		int nok = NOK(this->denum_, rhs.denum_);
		this->num_ = this->num_ * nok / this->denum_ + rhs.num_ * nok / rhs.denum_;
		this->denum_ = nok;
		this->reduce();
		return *this;
	}
	Rational& Rational::operator-=(const Rational& rhs)
	{
		return this->operator+=(-rhs);
	}
	Rational& Rational::operator*=(const Rational& rhs)
	{
		this->num_ = this->num_ * rhs.num_;
		this->denum_ = this->denum_ * rhs.denum_;
		this->reduce();
		return *this;
	}
	Rational& Rational::operator/=(const Rational& rhs)
	{
		if (rhs == Rational{ 0,1 })
			throw DivisionByZeroError();
		this->num_ = this->num_ * rhs.denum_;
		this->denum_ = this->denum_ * rhs.num_;
		this->reduce();
		return *this;
	}
	bool Rational::operator==(const Rational& rhs) const
	{
		return (this->num_ == rhs.num_ && 
			this->denum_ == rhs.denum_);
	}
	bool Rational::operator!=(const Rational& rhs) const
	{
		return !this->operator==(rhs);
	}
	bool Rational::operator<(const Rational& rhs) const
	{
		int nok = NOK(this->denum_, rhs.denum_);
		return (this->num_ * nok / this->denum_ < rhs.num_ * nok / rhs.denum_);
	}
	bool Rational::operator>(const Rational& rhs) const
	{
		return rhs.operator<(*this);
	}
	bool Rational::operator>=(const Rational& rhs) const
	{
		return !this->operator<(rhs);
	}
	bool Rational::operator<=(const Rational& rhs) const
	{
		return !this->operator>(rhs);
	}
	Rational Rational::operator-() const {
		return Rational{ -num_, denum_ };
	}

	Rational Rational::operator+() const {
		return (*this);
	}


	Rational& Rational::operator++() {
		num_ += denum_;
		this->reduce();
		return (*this);
	}

	Rational& Rational::operator--() {
		num_ -= denum_;
		this->reduce();
		return (*this);
	}


	Rational Rational::operator++(int)
	{
		Rational copy{ *this };
		this->operator++();
		return copy;
	}

	Rational Rational::operator--(int) 
	{
		Rational copy{ *this };
		this->operator--();
		return copy;
	}


	Rational Rational::operator+(const Rational& rhs) const 
	{
		Rational copy{ *this };
		return copy += rhs;
	}

	Rational Rational::operator-(const Rational& rhs) const 
	{
		Rational copy{ *this };
		return copy -= rhs;
	}

	Rational Rational::operator*(const Rational& rhs) const 
	{
		Rational copy{ *this };
		return copy *= rhs;
	}

	Rational Rational::operator/(const Rational& rhs) const 
	{
		Rational copy{ *this };
		return copy /= rhs;
	}
	int Rational::NOD(int a, int b)
	{
		while (a != 0) 
		{
			b = b % a;
			std::swap(a, b);
		}
		return std::abs(b);
	}
	int Rational::NOK(int a, int b)
	{
		return a * b / NOD(a, b);
	}
	void Rational::reduce()
	{
		if (denum_ < 0)
		{
			num_ *= -1;
			denum_ *= -1;
		}
		int nod = NOD(num_, denum_);
		if (nod != 0)
		{
			num_ /= nod;
			denum_ /= nod;
		}
		return;
	}
	std::ostream& operator<<(std::ostream& ostream, const Rational& data) {
		ostream << data.num_ << data.kSeparator << data.denum_;
		return ostream;
	}
	void Rational::SetValues(int num, int denum) {
		num_ = num;
		denum_ = denum;
		reduce();
		return;
	}
	std::istream& operator>>(std::istream& istream, Rational& data) {
		int num(0);
		char separator(0);
		int denum(0);

		istream >> num;
		istream.get(separator);
		if (!istream.bad()) {
			if (separator != Rational::kSeparator) {
				istream.setstate(std::ios_base::failbit);
			}
		}
		if (!std::isdigit(istream.peek())) {
			istream.setstate(std::ios_base::failbit);
		}
		istream>>denum;
		data.SetValues(num, denum);
		return istream;
	}

