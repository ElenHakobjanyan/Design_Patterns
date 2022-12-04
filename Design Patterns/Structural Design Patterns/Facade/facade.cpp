#include<iostream>
#include<tuple>
#include<vector>


// fast food ordering seasonal pack facade

class IItem
{
public:

protected:
	double m_cost;
};

class Drink : public IItem
{
public:
	Drink(double cost, double size)
		: cup_size(size)
	{
		m_cost = cost;
	}

protected:
	double cup_size;
};



class Food : public IItem
{
public:
	Food(double cost)
	{
		m_cost = cost;
	}

protected:
	//type
};

class Fast_Food_Point
{
public:
	void addToOrder(IItem* it, size_t s = 1)
	{
		orders.push_back(std::make_tuple(it, s));
	}

	void delFromOrder(IItem* it, size_t count = 1)
	{
		for (auto elem : orders)
		{
			if (std::get<0>(elem) == it)
			{
				if (std::get<1>(elem) > count)
				{
					std::get<1>(elem) -= count;
					return;
				}
				else
				{
					std::erase(orders, elem);
				}
			}
		}
	}

	bool makePurchase() { return 1; }

	void printReceipt(int order_number) 
	{
		std::cout << "Order number: " << order_number << "\n";
	}

	int getOrderNumber()
	{
		order_count++;
		return order_count;
	}

	void HolidayCombo()
	{
		Drink* cola = new Drink(300.0, 1.5);
		Food* burger = new Food(850.0);
		Food* fries = new Food(450.0);

		addToOrder(cola, 2);
		addToOrder(burger, 2);
		addToOrder(fries, 2);

		if (makePurchase())
		{
			printReceipt(getOrderNumber());
		}
	}

private:
	std::vector<std::tuple<IItem*, size_t>> orders;
	static int order_count;
};

int Fast_Food_Point::order_count = 0;

int main()
{
	Fast_Food_Point point;

	point.HolidayCombo();


	return 0;
}