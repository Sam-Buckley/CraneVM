#include <stream.hpp>
#include <reader.hpp>

void test_stream_init() {
    // Write the values \38 \1 \5 to test.cb
    std::ofstream file("test.cb", std::ios::binary);
    file << static_cast<char>(39) << '\1' << '\5';
    //print the contents of the file
    auto contents = Reader("test.cb").read();

    file.close();
    
    // Initialize the stream with the path test.cb
    Stream stream("test.cb");
    
    // Read the file
    stream.read();
    stream.print();
}

int main() {
    test_stream_init();
    return 0;
}