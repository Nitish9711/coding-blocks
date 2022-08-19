// Lets say in now clients wants variety in viechle type as well so there will be too many if else block 
// like we have to if it is car then i want toyta ,tata etc.
// Difference between Abstract Factory and Factory pattern
// Our factory design pattern was creating concreting classes or objects 
// Our abstarct pattern is going to create factories that is going to create object

//Button 
#include<bits/stdc++.h>
using namespace std;

class IButton{
    public:
        virtual void press()=0;
};
class MacButton:public IButton{
    public: 
        void press(){
            cout<<"mac button pressed"<<endl;
        }
};
class WinButton:public IButton{
    public: 
        void press(){
            cout<<"Windows button pressed"<<endl;
        }
};
class ITextBox{
    public:
        virtual void showText()=0;
};
class MacTextBox:public ITextBox{
    public: 
        void showText(){
            cout<<"mac Text showed "<<endl;
        }
};
class WinTextBox:public ITextBox{
    public: 
        void showText(){
            cout<<"Windows Text showed"<<endl;
        }
};
class IFactory{
    public: 
        virtual IButton* CreateButton() =0;
        virtual ITextBox* CreateTextBox() =0;
};
class MacFactory: public IFactory{
    public:
        IButton * CreateButton(){
            return new MacButton;
        }
        ITextBox* CreateTextBox(){
            return new MacTextBox;
        }
};
class WinFactory: public IFactory{
    public:
        IButton * CreateButton(){
            return new WinButton;
        }
        ITextBox* CreateTextBox(){
            return new WinTextBox;
        }
};

class GUIAbstractFactory{
    public:
        static IFactory* CreateFactory(string osType){
            if(osType == "windows"){
                return new WinFactory();
            }
            else if(osType == "mac"){
                return new MacFactory();
            }
            else
                return new MacFactory();
        } 
};
int main(){
    cout<<"Enter you machine os"<<endl;
    string osType;
    cin>>osType;
    IFactory* fact = GUIAbstractFactory::CreateFactory(osType);

    IButton* button = fact->CreateButton();   
    button->press();
    ITextBox *textBox = fact->CreateTextBox();
    textBox->showText();
}