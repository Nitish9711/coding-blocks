stack<int> s;
 
int minEle = -1;
MinStack::MinStack() {
    while(!s.empty()){
        s.pop();
    }
    min = -1;
}

void MinStack::push(int x) {
   if (s.empty())
        {
            s.push(x);
            min = x;
        }
        else if (x > min) {
            s.push(x);
        }
        else {
            s.push(2*x - min);
            min = x;
        }
}

void MinStack::pop() {
    if (s.empty()) {
           return;
        }
 
        int top = s.top();
        if (top < min) {
            min = 2*min - top;
        }
        s.pop();
}

int MinStack::top() {
    if(s.empty())
        return -1;
    return s.top();
}

int MinStack::getMin() {
    if(s.empty())
        return -1;
    return min;
}

