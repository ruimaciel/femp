#include <persistence/LoadPatternRepository.h++>

namespace gui {
namespace persistence {

LoadPatternRepository::LoadPatternRepository(std::shared_ptr<gui::Model> model)
    : m_domain_model(model)
{

}

std::vector<fem::LoadPattern> LoadPatternRepository::getLoadPatternList() const
{
    return m_domain_model->getLoadPatternList();
}

} // namespace persistence
} // namespace gui
