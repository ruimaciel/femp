#include <libfemp/GlobalDofMap.h++>

#include <libfemp/FemException.h++>


namespace fem
{


GlobalDofMap::GlobalDofMap()
{
}


void 
GlobalDofMap::clear()
{
	this->m_global_dof_map.clear();
}


void 
GlobalDofMap::pushGlobalDof(GlobalDof const &new_gdof)
{
	struct MappingData new_data;

	// generates a new index value
	new_data.index = this->m_global_dof_map.size();

	std::pair<GlobalDof, MappingData> new_gdof_entry(new_gdof, new_data);
	this->m_global_dof_map.insert(new_gdof_entry);
}


size_t 
GlobalDofMap::getIndex(GlobalDof const &gdof) const
{
	std::map<GlobalDof, MappingData>::const_iterator it;
	it = this->m_global_dof_map.find(gdof);

	if(it == this->m_global_dof_map.end())
	{
		throw FemException("Invalid global dof");
	}

	// return the current index
	return it->second.index;

}


}	// namespace fem
