#include <iostream>

enum currency {USD, AMD};

std::string GerCurrName(currency c)
{
	switch (c)
	{
	case USD:
		return "USD";
	case AMD:
		return "AMD";
	default:
		return "ERR_CURR";
	}
}

// Target Interface

class IProduct
{
public:
	virtual void PrintPrice() = 0;
	virtual void PrintCurrency() = 0;
protected:
	double price;
	currency curr;
};

// Target Implementation

class Camera : public IProduct
{
public:
	void PrintPrice() override
	{
		std::cout << "Product: camera, Price: " << price << std::endl;
	};
	void PrintCurrency() override
	{
		std::cout << "Currency: " << GerCurrName(curr) << std::endl;
	};

	double GetPrice()
	{
		return price;
	}
	currency GetCurr()
	{
		return curr;
	}
private:
	double price{155};
	currency curr = USD;
};

// Adaptee

class CurrCalc
{
public:
	CurrCalc(double m)
		: USD(m) {}

	double USDtoAMDconverter()
	{
		return USD * rate;
	};
	void PrintValue()
	{
		std::cout << "Amount: " << USDtoAMDconverter() << std::endl;
	};

	currency GetCurr()
	{
		return curr;
	}
private:
	double USD;
	double rate{ 396.7 };
	currency curr = AMD;
};

// Adapter

class CurrencyAdapter : public IProduct
{
public:
	CurrencyAdapter(CurrCalc* c)
		: calc(c)
	{}

	void PrintPrice() override
	{
		calc->PrintValue();
	};
	void PrintCurrency() override
	{
		std::cout << "New curr: " << GerCurrName(calc->GetCurr()) << std::endl;
	};

private:
	CurrCalc* calc;
};

int main()
{
	Camera* cam_ptr = new Camera();

	CurrCalc* calc_ptr = new CurrCalc(cam_ptr->GetPrice());

	IProduct* ptr = new CurrencyAdapter(calc_ptr);

	std::cout << "\nPRODUCT\n";
	cam_ptr->PrintPrice();
	cam_ptr->PrintCurrency();

	std::cout << "\nCALCULATED CURRENCY\n";
	calc_ptr->PrintValue();
	std::cout << "Calc curr: " << GerCurrName(calc_ptr->GetCurr()) << std::endl;

	std::cout << "\nCALL WITH ADAPTER\n";
	ptr->PrintPrice();
	ptr->PrintCurrency();
}