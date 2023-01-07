
#include <iostream>
#include <string>
#include <vector>


class IElement
{
public:
	virtual void show() = 0;

	virtual std::string getId() = 0;

	virtual void delElement(IElement*, std::vector<IElement*>) = 0;

private:
	std::string m_id;
};

class Element : public IElement
{
public:
	Element() = delete;

	Element(std::string name)
	{
		m_id = name;
	}

	std::string getId() override
	{
		return m_id;
	}

	bool isSameElement(IElement* el)
	{
		if (el->getId() == m_id)
		{
			return true;
		}
		return false;
	}

	void delElement(IElement* el, std::vector<IElement*> v)
	{
		if (this->isSameElement(el))
		{
			remove(v.begin(), v.end(), el);
			// delete this;
			// not working//??
		}
	}

	void show() override
	{
		std::cout << "Element: " << m_id << "\n";
	}

private:
	std::string m_id;
};

class ElemmGroup : public IElement
{
public:
	ElemmGroup()
		: m_id("Group_0")
	{};

	ElemmGroup(std::string name)
	{
		m_id = "Group_" + name;
	}

	std::string getId() override
	{
		return m_id;
	}

	void addElement(IElement* el)
	{
		m_elements.push_back(el);
	}

	void delElement(IElement* el)
	{
		this->delElement(el, m_elements);
	}

	void delElement(IElement* el, std::vector<IElement*> v) override
	{
		for (auto obj : m_elements)
		{
			obj->delElement(el, v);
		}
	}

	void show() override
	{
		for (auto obj : m_elements)
		{
			obj->show();
		}
	}

private:
	std::string m_id;
	std::vector<IElement*> m_elements;
};



class cSlide : public ElemmGroup
{
public:
	cSlide(std::string name)
	{
		m_id = "Slide_" + m_id + name;
	}

private:
	std::string m_id;
	std::vector<IElement*> m_elements;
};




int main()
{
	cSlide* p_slide = new cSlide("s1");

	// element without grouping
	Element* p_elem = new Element("square_");
	p_slide->addElement(p_elem);

	// fill p_group with two elements
	ElemmGroup* p_group = new ElemmGroup("eg2");
	p_elem = new Element("triangle_");
	p_group->addElement(p_elem);
	p_elem = new Element("circle_");
	p_group->addElement(p_elem);

	// adding both group and element to slide group (aka root group)
	p_slide->addElement(p_group);

	// recursively gonna call show on every leaf element
	p_slide->show();

	//std::cout << "--------------------------------------------------------\n";
	//// checking if del works
	//p_slide->delElement(p_elem);
	//p_slide->show();

	return 0;
}