#include <fstream>
#include <iostream>


struct file_object {
    public:
        file_object(std::string path)
        {
            this->path = path;
            this->stream = nullptr;
        }

        bool is_closed()
        {
            return !(this->stream != nullptr && this->stream->is_open());
        }

        void open(std::ios_base::openmode mode)
        {
            std::shared_ptr<std::fstream> s(new std::fstream());
            this->stream = s;
            this->stream->open(this->path, mode);
        }

        void close()
        {
            if (!is_closed())
                this->stream->close();
            this->stream = nullptr;
        }

        void operator<<(const char* message)
        {
            open(std::ios::out);
            if (is_closed())
            {
                std::cerr << "error: could not open file '"
                          << this->path
                          << "' to write"
                          << std::endl;
                std::exit(1);
            }

            *(this->stream) << message;
            close();
        }

        void operator>>(std::string buffer)
        {
            open(std::ios::in);
            if (is_closed())
            {
                std::cerr << "error: could not open file '"
                    << this->path
                    << "' to read"
                    << std::endl;
                std::exit(1);
            }


            *(this->stream) >> buffer;
            close();
        }

    private:
        std::string path;
        std::shared_ptr<std::fstream> stream;
};


int main(int argc, const char* const* argv)
{
    file_object file("test.txt");
    file << "Some text.\nSome text.\nSome text.\n";

    std::string buffer;
    file >> buffer;
    std::cout << "from test: " << buffer << std::endl;

    return 0;
}
