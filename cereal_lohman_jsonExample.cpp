#include <string>
#include <vector>
#include <fstream>
#include <nlohmann/json.hpp>

#include <cereal/cereal.hpp>
#include <cereal/archives/binary.hpp>
#include <cereal/archives/json.hpp>
#include <cereal/types/vector.hpp>

using namespace std;
using json = nlohmann::json;

static constexpr char sampleFile[] = "test.json";
static constexpr char sampleFile1[] = "formatted_test.json";

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

    template<class Archive>
      void serialize(Archive & ar)
      {
        ar( CEREAL_NVP(name),
            CEREAL_NVP(sex),
            CEREAL_NVP(height),
            CEREAL_NVP(weight),
            CEREAL_NVP(eyeColor) );
      }
};

void to_json(json& j, const Human& p) 
{
    j = json{{"name", p.name}, {"sex", p.sex},
            {"height", p.height},{"weight", p.weight},{"eyeColor", p.eyeColor}};
}

int main()
{
    std::ofstream using_lohmanJson(sampleFile);
    std::ofstream using_cerealJson(sampleFile1);
    
    vector<Human> vec ={{"Rizwan",Sex::Male,5.10,200.451,"Brown"},
        {"Katy",Sex::Female,5.8,150.48,"Brown"}};

    json j(vec);
    
    using_lohmanJson << std::setw(4) << j << std::endl;

    cereal::JSONOutputArchive archive(using_cerealJson,cereal::JSONOutputArchive::Options(1));

    archive(vec);

    return 0;
}