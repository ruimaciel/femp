
#include <libfemp/mesh/MeshModel.h++>

#include "gtest/gtest.h"
#include "mesh/src/MeshModelImpl.h++"

namespace {

TEST(libfemp_meshmodel, Given_InitializedModel_When_NoElementWasAdded_Then_NumberOfElementsIsZero) {
	// Given
	std::shared_ptr<fem::mesh::MeshModel> m = std::make_shared<fem::mesh::MeshModelImpl>();

	// When

	// Then
	EXPECT_EQ(m->numberOfElements(), 0);
}

}  // namespace

int main(int argc, char** argv) {
	::testing::InitGoogleTest(&argc, argv);
	return RUN_ALL_TESTS();
}
