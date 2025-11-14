#include <iostream>
#include <fstream>

class LogMessage {
public:
    enum class Type
    {
        WARNING,
        ERROR,
        FATAL_ERROR,
        UNKNOW_MESSAGE
    };
    LogMessage(Type type, const std::string& message) : _type(type), _message(message) {}

    Type type() const {
        return _type;
    }

    const std::string& message() const {
        return _message;
    }
private:
    Type _type;
    std::string _message;
};

class LogMessageHandler
{
private:
    std::shared_ptr<LogMessageHandler> _nextHandler = nullptr;
public:
    virtual ~LogMessageHandler() {}

    std::shared_ptr<LogMessageHandler> next(std::shared_ptr<LogMessageHandler> nextHandler) {
        _nextHandler = nextHandler;
        return nextHandler;
    }

    virtual void handle(const LogMessage& log) {
        if (_nextHandler)
        {
            _nextHandler->handle(log);
        }
    }
};

class WarningHandler : public LogMessageHandler
{
public:
    void handle(const LogMessage& log) override {
        if (log.type() == LogMessage::Type::WARNING)
        {
            std::cout << log.message() << std::endl;
        }
        else
        {
            return LogMessageHandler::handle(log);
        }
    }
};

class ErrorHandler : public LogMessageHandler
{
private:
    std::ofstream fout;
public:
    ErrorHandler(const std::string& filename) {
        fout.open(filename, std::ios::app);
        if (!fout.is_open())
        {
            std::cout << "Error opening LOG file!" << std::endl;
        }
    }

    void handle(const LogMessage& log) override {
        if (log.type() == LogMessage::Type::ERROR)
        {
            fout << log.message() << std::endl;
        }
        else
        {
            return LogMessageHandler::handle(log);
        }
    }

    ~ErrorHandler() {
        fout.close();
    }
};

class FatalErrorHandler : public LogMessageHandler
{
public:
    void handle(const LogMessage& log) override {
        if (log.type() == LogMessage::Type::FATAL_ERROR)
        {
            throw std::runtime_error("FATAL_ERROR!");
        }
        else
        {
            return LogMessageHandler::handle(log);
        }
    }
};

class UnknowErrorHandler : public LogMessageHandler
{
public:
    void handle(const LogMessage& log) override {
        if (log.type() == LogMessage::Type::UNKNOW_MESSAGE)
        {
            throw std::runtime_error("Not processed message!");
        }
        else
        {
            return LogMessageHandler::handle(log);
        }
    }
};

int main() {
    std::shared_ptr ptrWarning = std::make_shared<WarningHandler>();
    std::shared_ptr ptrError = std::make_shared<ErrorHandler>("Log.txt");
    std::shared_ptr ptrFatalError = std::make_shared<FatalErrorHandler>();
    std::shared_ptr ptrUnknown = std::make_shared<UnknowErrorHandler>();
    ptrFatalError->next(ptrError)->next(ptrWarning)->next(ptrUnknown);

    LogMessage mess1(LogMessage::Type::WARNING, "Warning message");
    LogMessage mess2(LogMessage::Type::ERROR, "Error message");
    LogMessage mess3(LogMessage::Type::FATAL_ERROR, "Fatal error message");
    LogMessage mess4(LogMessage::Type::UNKNOW_MESSAGE, "Unknow error message");

    try
    {
        //ptrFatalError->handle(mess1);
        //ptrFatalError->handle(mess2);
        //ptrFatalError->handle(mess3);
        ptrFatalError->handle(mess4);
    }
    catch (std::exception& e)
    {
        std::cout << e.what() << std::endl;
    }

    return 0;
}