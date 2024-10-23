#include <string>
#include <vector>
#include <iostream>
#include <filesystem>
#include <fstream>

int main()
{
  std::ofstream photos("myfile.txt");
  bool hascopy = false;
  std::string i;
  std::vector<std::string> pc_photos = {}, phone_photos = {}, no_copy = {};
  std::string pathinPC = "D:/Downloads"; // add your path here
  std::string pathinPhone = "D:/zdjecia mielno";   // add your path here
  for (const auto &element : std::filesystem::directory_iterator(pathinPC))
  {
    i = element.path().filename().string();
    // std::cout << i << std::endl;
    pc_photos.push_back(i);
  }
  for (const auto &element : std::filesystem::directory_iterator(pathinPhone))
  {
    i = element.path().filename().string();
    // std::cout << i << std::endl;
    phone_photos.push_back(i);
  }

  for (int i = 0; i < phone_photos.size(); ++i)
  {
    for (int j = 0; j < pc_photos.size(); ++j)
    {
      if (phone_photos[i] == pc_photos[j])
      {
        hascopy = true;
      }
    }
    if (!hascopy)
    {
      photos<<phone_photos[i]<<std::endl;
      no_copy.push_back(phone_photos[i]);
    }
    hascopy = false;
  }
    photos.close();

  return 0;
}