#include <string>
#include <vector>
#include <fstream>
#include <nlohmann/json.hpp>
using namespace std;
using json = nlohmann::json;

static constexpr char sampleFile[] = "test.json";

enum class Sex
{
    Male = 0,
    Female
};

struct Human
{
    std::string name;
    Sex sex;
    float height;
    float weight;
    string eyeColor;
};

void to_json(json& j, const Human& p) 
{
    j = json{{"name", p.name}, {"sex", p.sex},
            {"height", p.height},{"weight", p.weight},{"eyeColor", p.eyeColor}};
}

int main()
{
    std::ofstream ofs(sampleFile);
    
    vector<Human> vec ={{"Rizwan",Sex::Male,5.10,200.451,"Brown"},
        {"Katy",Sex::Female,5.8,150.48,"Brown"}};

    json j(vec);
    
    ofs << std::setw(4) << j << std::endl;

    return 0;
}