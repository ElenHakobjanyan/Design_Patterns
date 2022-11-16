#include <iostream>
#include <string>

bool IsValid(std::string);

class User {
public:
	User(std::string username, std::string mail, std::string password)
		: m_username(username)
		, m_mail(mail)
		, m_password(password) {}

	void ChangePassword(std::string old_password, std::string new_password)
	{
		if (old_password == new_password)
		{
			std::cout << "Same as old password.\n";
			return;
		}
		if (IsValid(new_password))
		{
			m_password = new_password;
			std::cout << "Password changed succesfully.\n";
		}
		else
		{
			std::cout << "Invalid new password. Change it by requirements.\n";
		}
	}

private:
	std::string m_username;
	std::string m_mail;
	std::string m_password;
};

class BaseValidator {
public:
	explicit BaseValidator(std::string str)
		: m_str(str) {}

	BaseValidator* SetNext(BaseValidator* checker)
	{
		if (next)
		{
			next->SetNext(checker);
		}
		else
		{
			next = checker;
		}

		return next;
	}

	int GetStatus()
	{
		return m_status;
	}

	void ResetStatus()
	{
		m_status = 0;
	}

	virtual void check() 
	{
		m_status++;
		if (next) next->check();
	}

protected:
	std::string m_str;

private:
	BaseValidator* next{ nullptr };
	static int m_status;
};

int BaseValidator::m_status = 0;


class ValidatorRightSymbols : public BaseValidator
{
public:
	explicit ValidatorRightSymbols(std::string str)
		: BaseValidator(str) {}

	void check() override
	{
		// pass if contains only 
		// a-z
		// A-Z
		// 0-9
		// !@#$%^&*()_+-=
		if (true)
		{
			BaseValidator::check();
			std::cout << "ValidatorRightSymbols: valid\n";
		}
		else
		{
			std::cout << "ValidatorRightSymbols: invalid\n";
		}
	}
};

class ValidatorRightLength : public BaseValidator
{
public:
	explicit ValidatorRightLength(std::string str)
		: BaseValidator(str) {}

	void check() override
	{
		// pass if str length is in [8; 32] range
		if (m_str.length() >= 8 && m_str.length() <= 32)
		{
			BaseValidator::check();
			std::cout << "ValidatorRightLength: valid\n";
		}
		else
		{
			std::cout << "ValidatorRightLength: invalid\n";
		}
	}
};

class ValidatorContainsAlph : public BaseValidator
{
public:
	explicit ValidatorContainsAlph(std::string str)
		: BaseValidator(str) {}

	void check() override
	{
		// pass if contains at least one upper case letter and at least one lowercase
		if (true)
		{
			BaseValidator::check();
			std::cout << "ValidatorContainsAlph: valid\n";
		}
		else
		{
			std::cout << "ValidatorContainsAlph: invalid\n";
		}
	}
};

class ValidatorContainsNumbers : public BaseValidator
{
public:
	explicit ValidatorContainsNumbers(std::string str)
		: BaseValidator(str) {}

	void check() override
	{
		// pass if contains at least one number
		if (true)
		{
			BaseValidator::check();
			std::cout << "ValidatorContainsNumbers: valid\n";
		}
		else
		{
			std::cout << "ValidatorContainsNumbers: invalid\n";
		}
	}
};

class ValidatorContainsSpecialSymbols : public BaseValidator
{
public:
	explicit ValidatorContainsSpecialSymbols(std::string str)
		: BaseValidator(str) {}

	void check() override
	{
		// pass if contains at least one of those symbols:  !@#$%^&*()_+-=
		if (true)
		{
			BaseValidator::check();
			std::cout << "ValidatorContainsSpecialSymbols: valid\n";
		}
		else
		{
			std::cout << "ValidatorContainsSpecialSymbols: invalid\n";
		}
	}
};


bool IsValid(std::string pw)
{
	// all of this could have been done in much easier way, probably:)
	
	BaseValidator* root = new BaseValidator{ pw };
	root->ResetStatus();

	ValidatorRightSymbols*				v1 = new ValidatorRightSymbols				{ pw };
	ValidatorRightLength*				v2 = new ValidatorRightLength				{ pw };
	ValidatorContainsAlph*				v3 = new ValidatorContainsAlph				{ pw };
	ValidatorContainsNumbers*			v4 = new ValidatorContainsNumbers			{ pw };
	ValidatorContainsSpecialSymbols*	v5 = new ValidatorContainsSpecialSymbols	{ pw };

	root->SetNext(v2)->SetNext(v1)->SetNext(v3)->SetNext(v4)->SetNext(v5);

	root->check();

	std::cout << "STATUS: " << root->GetStatus() << "\n";

	return (root->GetStatus() > 5);
}


void TestCase(User* u, std::string new_pw)
{
	std::cout << "\nNew password: " << new_pw << std::endl;
	u->ChangePassword("RYCBAR123_dw", new_pw);
	std::cout << std::endl;
}

int main()
{
	User* u = new User("test_name", "SurelyRealPerson98@why.not", "RYCBAR123_dw");

	TestCase(u, "have not allowed symbols?");
	TestCase(u, "2short");
	TestCase(u, "onlylowercaseletters");
	TestCase(u, "Dont_Contain_Numbers");
	TestCase(u, "DontHaveASpecialSymbol123");
	TestCase(u, "Should_Be_Prefect_42");
}