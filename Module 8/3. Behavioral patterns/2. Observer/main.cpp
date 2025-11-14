#include <string>
#include <iostream>
#include <fstream>
#include <vector>

class Observer {
public:
    virtual ~Observer() {}
    virtual void onWarning(const std::string& message) {}
    virtual void onError(const std::string& message) {}
    virtual void onFatalError(const std::string& message) {}
};

class ObserverOnWarning : public Observer {
    void onWarning(const std::string& message) override {
        std::cout << message << std::endl;
    }
};

class ObserverOnError : public Observer {
private:
    std::ofstream fout;
public:
    ObserverOnError(std::string filename) {
        fout.open(filename, std::ios::app);
        if (!fout.is_open())
        {
            std::cout << "Error opening file: " << filename << std::endl;
        }
    }

    ~ObserverOnError() {
        fout.close();
    }

    void onError(const std::string& message) override {
        fout << message << std::endl;
    }
};

class ObserverOnFatalError : public Observer {
private:
    std::ofstream fout;
public:
    ObserverOnFatalError(std::string filename) {
        fout.open(filename, std::ios::app);
        if (!fout.is_open())
        {
            std::cout << "Error opening file: " << filename << std::endl;
        }
    }

    ~ObserverOnFatalError() {
        fout.close();
    }

    void onFatalError(const std::string& message) override {
        std::cout << message << std::endl;
        fout << message << std::endl;
    }
};

class Log
{
private:
    std::vector<Observer*> observers;
public:
    Log& addObserver(Observer* observer) {
        observers.push_back(observer);
        return *this;
    }

    Log& removeObserver(Observer* observer) {
        std::vector<Observer*>::iterator it =
            std::remove(observers.begin(), observers.end(), observer);
        observers.erase(it, observers.end());
        return *this;
    }

    void warning(const std::string& message) const {
        for (const auto& observer : observers)
        {
            observer->onWarning(message);
        }
    }

    void error(const std::string& message) const {
        for (const auto& observer : observers)
        {
            observer->onError(message);
        }
    }

    void fatalError(const std::string& message) const {
        for (const auto& observer : observers)
        {
            observer->onFatalError(message);
        }
    }
};

int main() {
    Log log;
    ObserverOnError message1("log.txt");
    ObserverOnWarning message2;
    ObserverOnFatalError message3("log.txt");

    log.addObserver(&message1).addObserver(&message2).addObserver(&message3);

    log.error("Error");
    log.warning("Warning");
    log.fatalError("Fatal Error");

    log.removeObserver(&message1).removeObserver(&message2).removeObserver(&message3);

    return 0;
}