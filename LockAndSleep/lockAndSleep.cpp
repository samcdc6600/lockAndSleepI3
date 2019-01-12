#include <fstream>
#include <sstream>
#include <cstdlib>


int getIntFromFile(const int rDefault, const std::string f);

int main(void)
{
  constexpr int DEFAULT_FILE_NUM {1};
  const int fileNum {getIntFromFile(DEFAULT_FILE_NUM, "/usr/home/cyan/.config/sleep/images/nextImage")};
  std::stringstream command {};
  command<<"/usr/home/cyan/.config/sleep/lock_sleep.sh "<<fileNum;
  system(command.str().c_str());

  return 0;
}


int getIntFromFile(const int rDefault, const std::string f)
{
    int ret {};
    std::ifstream in(f.c_str());
    if(in.is_open())
      {
        in>>ret;
        in.close();
      }
    else
      ret = rDefault;
    return ret;
}
