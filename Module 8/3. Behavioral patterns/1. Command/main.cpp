#include <string>
#include <iostream>
#include <fstream>

class LogCommand {
public:
    virtual ~LogCommand() = default;
    virtual void print(const std::string& message) = 0;
};

class ConsoleLogCommand : public LogCommand {
    void print(const std::string& message) override {
        std::cout << message << std::endl;
    }
};

class FileLogCommand : public LogCommand {
private:
    std::ofstream fout;
public:
    FileLogCommand(std::string filename) {
        fout.open(filename);
        if (!fout.is_open())
        {
            std::cout << "Error opening file: " << filename << std::endl;
        }
    }

    ~FileLogCommand() {
        fout.close();
    }

    void print(const std::string& message) override {
        fout << message << std::endl;
    }
};

void print(LogCommand& command, std::string message) {
    command.print(message);
}

int main() {
    ConsoleLogCommand c_log;
    FileLogCommand f_log("output.txt");

    print(c_log, "Hello Log!");
    print(f_log, "Hello Log!");

    return 0;
}