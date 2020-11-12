#include <iostream>

using namespace std;

// Component
class Beverage {
public:
    string description;

    Beverage() {
        description = "Unknown Beverage";
    };
    virtual double cost() = 0;

    virtual string getDescription() {
        return description;
    }

    void displayDescription() {
        cout << getDescription();
        cout << " : $" << cost() << endl;

    }

};

//ConcreteComponent, 음료수 클래스들
class DarkRoast : public Beverage {
public:
    DarkRoast() {
        description = "DarkRoast";
    };
    double cost() {
        return 0.99;
    }
};

class Decaf : public Beverage {
public:
    Decaf() {
        description = "Decaf Coffee";
    };
    double cost() {
        return 1.05;
    }
};

class Espresso : public Beverage {
public:
    Espresso() {
        description = "Americano";
    };
    double cost() {
        return 0.99;
    }
};

class HouseBlend : public Beverage {
public:
    HouseBlend() {
        description = "House Blend Coffee";
    };
    double cost() {
        return 0.89;
    }
};

// Decorator
class CondimentDecorator : public Beverage {
public:
    virtual string getDescription() {
        return 0;
    }
};

//ConcreteDecorator, 구체적인 첨가물들
class Milk : public CondimentDecorator {
public:
    Beverage* beverage;
    Milk(Beverage* beverage) {
        this->beverage = beverage;
    }

    string getDescription() {
        return (beverage->getDescription() + ", Milk");
    }

    double cost() {
        return 0.1 + beverage->cost();
    }
};

class Mocha : public CondimentDecorator {
public:
    Beverage* beverage;
    Mocha(Beverage* beverage) {
        this->beverage = beverage;
    }

    string getDescription() {
        return (beverage->getDescription() + ", Mocha");
    }

    double cost() {
        return 0.2 + beverage->cost();
    }
};

class Soy : public CondimentDecorator {
public:
    Beverage* beverage;
    Soy(Beverage* beverage) {
        this->beverage = beverage;
    }

    string getDescription() {
        return (beverage->getDescription() + ", Soy");
    }

    double cost() {
        return 0.15 + beverage->cost();
    }
};

class Whip : public CondimentDecorator {
public:
    Beverage* beverage;
    Whip(Beverage* beverage) {
        this->beverage = beverage;
    }

    string getDescription() {
        return (beverage->getDescription() + ", Whip");
    }

    double cost() {
        return 0.1 + beverage->cost();
    }
};


int main(int argc, char* argv[]) {
    Beverage* myEspresso = new Espresso();
    myEspresso->displayDescription();
    delete myEspresso;

    Beverage* myDarkRoast = new DarkRoast();
    myDarkRoast = new Mocha(myDarkRoast);
    myDarkRoast = new Mocha(myDarkRoast);
    myDarkRoast = new Whip(myDarkRoast);
    myDarkRoast->displayDescription();
    delete myDarkRoast;

    Beverage* myHouseBlend = new HouseBlend();
    myHouseBlend = new Soy(myHouseBlend);
    myHouseBlend = new Mocha(myHouseBlend);
    myHouseBlend = new Whip(myHouseBlend);
    myHouseBlend->displayDescription();
    delete myHouseBlend;
}