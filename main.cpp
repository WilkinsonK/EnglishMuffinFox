#include <fstream>
#include <iostream>

#include <argparse/argparse.hpp>

int main(int argc, const char* const* argv)
{
    // Initialize our root parser.
    // Apply any details that might be helpful for the user.
    argparse::ArgumentParser rootProgram("emf");
    rootProgram.add_description("example cli program");

    // Setup any options/arguments used in this cli program.
    rootProgram.add_argument("file");

    // Parse given arguments (if any) raising an error for
    // the user if something goes wrong.
    try {
        rootProgram.parse_args(argc, argv);
    } catch (std::runtime_error& err) {
        std::cerr << "error: " << err.what() << std::endl;
        return -1;
    }

    std::fstream sfile;
    std::string file(rootProgram.get<std::string>("file"));

    sfile.open(file, std::ios::out);
    sfile << "Some text.\nSome text.\nSome text.\n";
    sfile.close();

    char readBuffer[10 * 1024];
    std::vector<char*> data;

    sfile.open(file, std::ios::in);
    while (sfile >> std::noskipws >> readBuffer)
    {
        uint32_t readBytes = 0;
        for (auto ch : readBuffer)
        {
            std::cout << ch;
            readBytes++;
        }
        data.push_back(readBuffer);
        std::cout << "# of Bytes Read: " << readBytes << std::endl;
        std::cout << readBuffer;
    }
    sfile.close();

    for (auto i : data)
    {
        std::cout << i;
    }
    std::cout << std::endl;

    return 0;
}
