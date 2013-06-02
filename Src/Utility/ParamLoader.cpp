#include "ParamLoader.h"

namespace ait
{
	ParamLoader* ParamLoader::Instance()
	{
	  static ParamLoader instance;

	  return &instance;
	}
};