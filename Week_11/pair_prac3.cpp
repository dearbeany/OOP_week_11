#include <iostream>
#include <string>

using namespace std;

enum BeverageSize {
	TALL,
	GRANDE,
	VENTI
};
// Component
class Beverage {
public:
	string description;
	BeverageSize size;

	Beverage() {
		description = "Unknown Beverage";
	}

	Beverage(BeverageSize orderSize) {
		description = "Unknown Beverage";
		setSize(orderSize);
	}

	virtual string getDescription() {
		return description;
	}

	virtual double cost() = 0;

	virtual BeverageSize getSize() {
		return size;
	}
	void setSize(BeverageSize orderSize) {
		size = orderSize;
	}

	void displayDescription() {
		cout << getDescription();
		cout << " $" << cost() << endl;
	}
};

class DarkRoast : public Beverage {
public:
	DarkRoast() {
		description = "Dark Roast Coffee";
	}

	DarkRoast(BeverageSize orderSize) : Beverage(orderSize) {
		description = "Dark Roast Coffee";
	}
	double cost() {
		return 0.99;
	}
	
};

class Decaf : public Beverage {
public:
	Decaf() {
		description = "Decaf Coffee";
	};

	Decaf(BeverageSize ordersize) : Beverage(ordersize) {
		description = "Decaf Coffee";
	}
	double cost() {
		return 1.05;
	}
};

class Espresso : public Beverage {
public:
	Espresso() {
		description = "Americano";
	};

	Espresso(BeverageSize orderSize) : Beverage(orderSize) {
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

	HouseBlend(BeverageSize orderSize) : Beverage(orderSize) {
		description = "House Blend Coffee";
	};

	double cost() {
		return 0.89;
	}
};

// Decorator
class CondimentDecorator : public Beverage {
public:
	CondimentDecorator() {}
	CondimentDecorator(BeverageSize orderSize) : Beverage(orderSize) {}

	virtual string getDescription() {
		return 0;
	}
};

class Milk : public CondimentDecorator {
public:
	Beverage* beverage;
	Milk(Beverage* beverage) : CondimentDecorator(beverage->getSize()) {
		this->beverage = beverage;
	}
	string getDescription() {
		return beverage->getDescription() +", Milk";
	}
	double cost() {
		if (getSize() == TALL)
			return beverage->cost() + 0.10;
		else if (getSize() == GRANDE)
			return beverage->cost() + 0.15;
		else if (getSize() == VENTI)
			return beverage->cost() + 0.20;
	}

};

class Mocha : public CondimentDecorator {
public:
	Beverage* beverage;
	Mocha(Beverage* beverage) : CondimentDecorator(beverage->getSize()) {
		this->beverage = beverage;
	}

	string getDescription() {
		return (beverage->getDescription() + ", Mocha");
	}

	double cost() {
		if (getSize() == TALL)
			return beverage->cost() + 0.20;
		else if (getSize() == GRANDE)
			return beverage->cost() + 0.25;
		else if (getSize() == VENTI)
			return beverage->cost() + 0.30;
	}
};


class Soy : public CondimentDecorator {
public:
	Beverage* beverage;
	Soy(Beverage* beverage) : CondimentDecorator(beverage->getSize()) {
		this->beverage = beverage;
	}

	string getDescription() {
		return (beverage->getDescription() + ", Soy");
	}

	double cost() {
		if (getSize() == TALL)
			return beverage->cost() + 0.15;
		else if (getSize() == GRANDE)
			return beverage->cost() + 0.20;
		else if (getSize() == VENTI)
			return beverage->cost() + 0.25;
	}
};


class Whip : public CondimentDecorator {
public:
	Beverage* beverage;
	Whip(Beverage* beverage) : CondimentDecorator(beverage->getSize()) {
		this->beverage = beverage;
	}

	string getDescription() {
		return (beverage->getDescription() + ", Whip");
	}

	double cost() {
		if (getSize() == TALL)
			return beverage->cost() + 0.10;
		else if (getSize() == GRANDE)
			return beverage->cost() + 0.15;
		else if (getSize() == VENTI)
			return beverage->cost() + 0.20;
	}
};


int main(int argc, char* argv[]){
		Beverage* bever1 = new DarkRoast(TALL);
		bever1 = new Milk(bever1);
		bever1 = new Mocha(bever1);
		bever1 = new Milk(bever1);
		bever1->displayDescription();

		Beverage* bever2 = new Espresso(GRANDE);
		bever2 = new Milk(bever2);
		bever2 = new Milk(bever2);
		bever2 = new Milk(bever2);
		bever2->displayDescription();

		Beverage* bever3 = new HouseBlend(VENTI);
		bever3 = new Whip(bever3);
		bever3 = new Milk(bever3);
		bever3 = new Soy(bever3);
		bever3 = new Mocha(bever3);
		bever3->displayDescription();
}
