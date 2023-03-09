#include "stack.h"
#include <iostream>
int main() {
    stack st;
    st.push('y');
    st.push('a');
    st.push('g');
    st.push('a');
    st.push('y');
    size_t size = st.size;
    for (size_t i = 0; i < size-1; i++) {
        std::cout << st.top() << ' ';
        st.pop();
    }
}