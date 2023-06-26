// builder design patterns is used when we have to complex objects which has a lot of configuartions
// for example car, computer
// Builder Pattern says that "construct a complex object from simple objects using step-by-step approach"

// Product – The product class defines the type of the complex
//  object that is to be generated by the builder pattern.

// Builder – This abstract base class defines all of the steps that must 
// be taken in order to correctly create a product. Each step is generally abstract as the actual 
// functionality of the builder is carried out in the concrete subclasses. The GetProduct method is used to return the final product. The builder class is often replaced with a simple interface.

// ConcreteBuilder – There may be any number of concrete builder classes inheriting from Builder. 
// These classes contain the functionality to create a particular complex product.

// Director – The director-class controls the algorithm that generates the final product object. 
// A director object is instantiated and its Construct method is called. The method includes a parameter
//  to capture the specific concrete builder object that is to be used to generate the product. 
//  The director then calls methods of the concrete builder in the correct order to generate the product object. 
//  On completion of the process, the GetProduct method of the builder object can be used to return the product.

#include <bits/stdc++.h>
using namespace std;
class Desktop
{
    string monitor;
    string keyboard;
    string mouse;
    string speaker;
    string ram;
    string processor;
    string motherBoard;

public:
    void setMonitor(string pMonitor);
    void setKeyboard(string pKeyboard);
    void setMouse(string pMouse);
    void setSpeaker(string pSpeaker);
    void setRam(string pRam);
    void setProcessor(string pProcessor);
    void setMotherBoard(string pMotherBoard);
    void showSpecs();
};

void Desktop::setMonitor(string pMonitor)
{
    monitor = pMonitor;
}
void Desktop::setKeyboard(string pKeyboard)
{
    keyboard = pKeyboard;
}
void Desktop::setMouse(string pMouse)
{
    mouse = pMouse;
}
void Desktop::setSpeaker(string pSpeaker)
{
    speaker = pSpeaker;
}
void Desktop::setRam(string pRam)
{
    ram = pRam;
}
void Desktop::setProcessor(string pProcessor)
{
    processor = pProcessor;
}
void Desktop::setMotherBoard(string pMotherBoard)
{
    motherBoard = pMotherBoard;
}
void Desktop::showSpecs()
{
    cout << "-----------------------------------" << endl;
    cout << "Monitor " << monitor << endl;
    cout << "keyboard " << keyboard << endl;
    cout << "mouse " << mouse << endl;
    cout << "speaker " << speaker << endl;
    cout << "ram " << ram << endl;
    cout << "processor " << processor << endl;
    cout << "motherBoard " << motherBoard << endl;
    cout << "-----------------------------------" << endl;
}

// Builder it mentions which functions has to be implemented;
class DesktopBuilder
{
protected:
    Desktop *desktop;

public:
    DesktopBuilder()
    {
        desktop = new Desktop();
    }
    virtual void buildMonitor() = 0;
    virtual void buildKeyBoard() = 0;
    virtual void buildMouse() = 0;
    virtual void buildSpeaker() = 0;
    virtual void buildRam() = 0;
    virtual void buildProcessor() = 0;
    virtual void buildMotherBoard() = 0;
    virtual Desktop *getDesktop()
    {
        return desktop;
    }
};

// Concrete Builder Basically it specifically tells which design patterns to follow
class DellDesktopBuilder : public DesktopBuilder
{
    void buildMonitor();
    void buildKeyBoard();
    void buildMouse();
    void buildSpeaker();
    void buildRam();
    void buildProcessor();
    void buildMotherBoard();
};

void DellDesktopBuilder::buildMonitor()
{
    desktop->setMonitor("Dell Monitor");
}
void DellDesktopBuilder::buildKeyBoard()
{
    desktop->setKeyboard("Dell Keyboard");
}
void DellDesktopBuilder::buildMouse()
{
    desktop->setMouse("Dell Mouse");
}
void DellDesktopBuilder::buildSpeaker()
{
    desktop->setSpeaker("Dell Speaker");
}
void DellDesktopBuilder::buildRam()
{
    desktop->setRam("Dell ram");
}
void DellDesktopBuilder::buildProcessor()
{
    desktop->setProcessor("Dell Processor");
}
void DellDesktopBuilder::buildMotherBoard()
{
    desktop->setMotherBoard("Dell Motherboard");
}

class HpDesktopBuilder : public DesktopBuilder
{
    void buildMonitor();
    void buildKeyBoard();
    void buildMouse();
    void buildSpeaker();
    void buildRam();
    void buildProcessor();
    void buildMotherBoard();
};

void HpDesktopBuilder::buildMonitor()
{
    desktop->setMonitor("Hp Monitor");
}
void HpDesktopBuilder::buildKeyBoard()
{
    desktop->setKeyboard("Hp Keyboard");
}
void HpDesktopBuilder::buildMouse()
{
    desktop->setMouse("Hp Mouse");
}
void HpDesktopBuilder::buildSpeaker()
{
    desktop->setSpeaker("Hp Speaker");
}
void HpDesktopBuilder::buildRam()
{
    desktop->setRam("Hp ram");
}
void HpDesktopBuilder::buildProcessor()
{
    desktop->setProcessor("Hp Processor");
}
void HpDesktopBuilder::buildMotherBoard()
{
    desktop->setMotherBoard("Hp MotherBoard");
}
// Director will use the builder to build the product
// builder has product/
// director has builder
class DesktopDirector
{
private:
    DesktopBuilder *desktopBuilder;

public:
    DesktopDirector(DesktopBuilder* pDesktopBuilder){
        desktopBuilder = pDesktopBuilder;
    }
    Desktop* getDesktop(){
        return desktopBuilder->getDesktop();
    }
    Desktop * BuildDesktop(){
        desktopBuilder->buildMonitor();
        desktopBuilder->buildMouse();
        desktopBuilder->buildRam();
        desktopBuilder->buildProcessor();
        desktopBuilder->buildKeyBoard();
        desktopBuilder->buildSpeaker();
        desktopBuilder->buildMotherBoard();
        return desktopBuilder->getDesktop();
    }
};

int main(){
    HpDesktopBuilder * hpDesktopBuilder = new HpDesktopBuilder();
    DellDesktopBuilder* dellDesktopBuilder= new DellDesktopBuilder();

    DesktopDirector* director1 = new DesktopDirector(hpDesktopBuilder);
    DesktopDirector* director2 = new DesktopDirector(dellDesktopBuilder);

    Desktop * desktop1 = director1->BuildDesktop();
    Desktop * desktop2 = director2->BuildDesktop();

    desktop1->showSpecs();
    desktop2->showSpecs();

    return 0;
}

//https://www.javatpoint.com/builder-design-pattern
//https://www.geeksforgeeks.org/builder-design-pattern/#:~:text=Advantages%20of%20Builder%20Design%20Pattern,optional%20parameters%20to%20the%20constructor.