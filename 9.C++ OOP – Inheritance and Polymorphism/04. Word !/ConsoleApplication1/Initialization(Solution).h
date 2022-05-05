#pragma once
#include<algorithm>
#include<string>
#include "Initialization.h"
#include "CommandInterface.h"

std::string unique, cut;

class Initializaiton : public CommandInterface
{
protected:
    class Paste : public TextTransform   {
    public:
        virtual void invokeOn(std::string& text, int startIndex, int endIndex) override
        {
            text.replace(startIndex, 1, cut);
        }
    };

    class Cut : public TextTransform
    {
    public:

        virtual void invokeOn(std::string& text, int startIndex, int endIndex) override
        {
            cut = text.substr(startIndex, endIndex);
            text.erase(startIndex, endIndex); // >= < 
        }
    };
public:
    Initializaiton(std::string& str) : CommandInterface(str)
    {
        unique = str;

    }

    virtual std::vector<Command> initCommands() override
    {

        std::vector<Command> x(CommandInterface::initCommands());

        x.push_back(Command("cut", std::make_shared<Cut>()));
        x.push_back(Command("paste", std::make_shared<Paste>()));

        return x;
    }
};

std::shared_ptr<CommandInterface> buildCommandInterface(std::string& str)
{
    std::shared_ptr<CommandInterface> a(new Initializaiton(str));

    a->init();

    return a;
}


/*
class buildCommandInterface {
protected:
	std::string& line;
public:
	buildCommandInterface(std::string& line) :line(line) {}

	class cutTransform :TextTransform {
	public:
		virtual void invokeOn(std::string& text, int startIndex, int endIndex) override {
			text.erase(startIndex, endIndex);
		}

		virtual std::vector<Command> initCommands()  {
			std::vector<Command> commands;
			//commands.push_back("cut", TextTransform);
			commands.push_back(Command("cut", std::make_shared<cutTransform>()));
			

			return commands;
		}

	};
	class pasteTransform : TextTransform {
	public:
		virtual void invokeOn(std::string& text, int startIndex, int endIndex) override {
			std::string paste;
			for (size_t i = startIndex; i < endIndex; i++)
			{
				paste += text[i];
			}
		}
	};
	virtual std::vector<Command> initCommands() {
		std::vector<Command> commands;

		commands.push_back(Command("paste", std::make_shared<pasteTransform>()));

		return commands;
	}
};
*/