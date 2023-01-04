
#include <iostream>
#include <vector>



class cCommand
{
public:
	
	void Exec()
	{
		std::cout << "--command executed\n";
	}
	
private:
};

class cApp 
{
public:
    cApp(const cApp& obj) = delete;

    static cApp* getInstance();

    void addCommand(cCommand* );

    void addCommandToHistory(cCommand* );

    void execute();

private:
    std::vector<cCommand*> m_commands;
    std::vector<cCommand*> m_cmd_history; // make circular buffer
    
	static cApp* instancePtr;

    cApp() {};
};


cApp* cApp::getInstance()
{
	if (instancePtr == nullptr)
	{
		instancePtr = new cApp();
	}

	return instancePtr;
}

void cApp::addCommand(cCommand* cmd)
{
	this->m_commands.push_back(cmd);
}

void cApp::addCommandToHistory(cCommand* cmd)
{
	this->m_cmd_history.push_back(cmd);
}

void cApp::execute()
{
	for (auto cmd : this->m_commands)
	{
		cmd->Exec();
		addCommandToHistory(cmd);
	}
}

cApp* cApp::instancePtr = nullptr;






int main() 
{
	cApp* obApp = cApp::getInstance();
	
	cCommand* c = new cCommand;
	obApp->addCommand(c);
	
	obApp->execute();

	return 0;
}