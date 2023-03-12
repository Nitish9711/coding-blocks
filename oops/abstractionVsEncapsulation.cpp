/*In C++, abstraction and encapsulation are two key principles of object-oriented programming
 that work together to help you create more modular, reusable, and robust code. Here are some examples 
 of abstraction and encapsulation in C++:

Abstraction Example:
Suppose you want to create a program that deals with geometric shapes such as rectangles, circles, 
and triangles. You could define a class for each shape, with member functions for calculating its area, 
perimeter, and other properties. However, you could also define an abstract class called Shape that provides
 a common interface for all shapes. This interface could include pure virtual functions such as getArea() 
 and getPerimeter(), which must be implemented by any class that derives from Shape. Here is an example:
 */
class Shape {
public:
  virtual double getArea() = 0;
  virtual double getPerimeter() = 0;
};

class Rectangle : public Shape {
private:
  double width, height;
public:
  Rectangle(double w, double h) : width(w), height(h) {}
  double getArea() override { return width * height; }
  double getPerimeter() override { return 2 * (width + height); }
};

class Circle : public Shape {
private:
  double radius;
public:
  Circle(double r) : radius(r) {}
  double getArea() override { return 3.14 * radius * radius; }
  double getPerimeter() override { return 2 * 3.14 * radius; }
};

// ...

Shape* s1 = new Rectangle(5, 10);
Shape* s2 = new Circle(2.5);
cout << "Area of s1: " << s1->getArea() << endl;
cout << "Perimeter of s2: " << s2->getPerimeter() << endl;

/*In this example, the Shape class defines an abstract interface for all shapes, while the Rectangle 
and Circle classes implement this interface with their own specific calculations for area and perimeter. 
By using the Shape interface, we can treat all shapes in a uniform way, without worrying about their specific 
implementation details.

Encapsulation Example:
Suppose you want to create a class that represents a bank account, with a balance and methods for 
withdrawing and depositing money. You could define public member functions for these operations, but 
this would expose the internal details of the account to the outside world. To prevent this, you can 
use encapsulation to hide the balance data member and provide a public interface for accessing it.
 Here is an example:*/
 class BankAccount {
private:
  double balance;
public:
  BankAccount() : balance(0) {}
  void deposit(double amount) { balance += amount; }
  bool withdraw(double amount) {
    if (amount > balance) {
      return false; // insufficient funds
    }
    balance -= amount;
    return true;
  }
  double getBalance() const { return balance; }
};

// ...

BankAccount account;
account.deposit(1000);
if (account.withdraw(500)) {
  cout << "Withdrawal successful. Balance: " << account.getBalance() << endl;
} else {
  cout << "Insufficient funds." << endl;
}
/*In this example, the balance data member is private, which means that it can only be accessed from
 within the BankAccount class. The deposit, withdraw, and getBalance member functions provide a public
  interface for modifying and accessing the balance. By encapsulating the balance data member, we ensure 
  that it can only be accessed through the defined interface, which helps to prevent errors and maintain
   the integrity of the account.*/

/**   Encapsulation and abstraction are two important concepts in object-oriented programming.
 *  Although they are related and often used together, they are different concepts.

Encapsulation refers to the practice of hiding the implementation details of a class from the outside 
world and exposing only the necessary information through well-defined interfaces. The implementation 
details of the class are hidden behind a public interface, which specifies how the class can be used by other parts of the program.
 Encapsulation is important for maintaining data integrity and for managing complexity in large programs. By hiding implementation details, 
 encapsulation allows the internal structure of a class to be modified without affecting other parts of the program.

Abstraction, on the other hand, refers to the process of creating abstract representations of real-world objects and concepts.
 Abstraction allows programmers to focus on the essential characteristics of an object or concept, while ignoring irrelevant details. 
 Abstraction is important for managing complexity and for creating reusable code. Abstraction is often achieved in object-oriented programming
  through the use of abstract classes and interfaces.

To summarize, encapsulation is concerned with hiding implementation details of a class, while abstraction is concerned with creating abstract 
representations of real-world objects and concepts. Encapsulation is a means of achieving abstraction, as it allows the essential characteristics 
of a class to be exposed through a well-defined interface, while hiding implementation details.*/