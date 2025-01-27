    #include <iostream>
    #include <filesystem>
    #include <vector>
    #include "FindWavFile.h"
  


    std::vector<std::string> FindWavFile(std::filesystem::path p)
    {

    std::vector<std::string> wfVec = {};
    for (const auto& entry : std::filesystem::directory_iterator(p))
    {
        if (entry.is_regular_file() && entry.path().extension() == ".wav")
        {
            wfVec.push_back(entry.path().filename().string());
            if (wfVec.size() == 9)
            {
                break;
            }
        }

    }

    return wfVec;

    }

    vector<string> FindWavFile(const string& Dir)
    {
        return vector<string>();
    }
