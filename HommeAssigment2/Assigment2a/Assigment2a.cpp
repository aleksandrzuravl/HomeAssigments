/*zhuravlev alexander st129760
    assigment 2a
*/
#include <iostream>
#include <fstream>
#include <filesystem>

int main()
{
    std::ifstream file("text.txt", std::ios_base::binary);
    int size = std::filesystem::file_size('text.txt');
    char *lst = new char[size];
    file.read(lst, size);
    
    
    
    char x;
    for(int i = 0; i < size/2; ++i){
        x = lst[i];
        lst[i]= lst[size - 1 - i];
        lst[size - 1 - i] = x;
     }
     
     
     std::ofstream outfile;
     std::outfile.open("temppdf.pdf", std::ios::binary|std::ios::out);
     outfile.write((char*)&lst,sizeof(lst));
     
     
     infile.close;
     outfile.close;
     
     delete[lst];
        
        
}
