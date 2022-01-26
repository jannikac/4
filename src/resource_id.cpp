#include <string>

class resource_id {
public:
  const std::string full_path;

  resource_id(const std::string &base_path, const std::string &file_title,
              const std::string &extension)
      : file_name_(file_title + "." + extension),
        full_path(base_path_ + "/" + file_name_) {}

private:
  const std::string base_path_;
  const std::string file_name_;
};