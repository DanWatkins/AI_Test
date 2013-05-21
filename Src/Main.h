#ifndef _aitest_MAIN_H
#define _aitest_MAIN_H

#include <iostream>

#include <vector>
#include <list>
#include <map>
#include <string>

#include <sstream>
#include <ostream>
#include <fstream>

#include <cstdlib>
#include <math.h>
#include <memory>
#include <new>

#include <climits>

#include <SFML/System.hpp>
#include <SFML/Window.hpp>
#include <SFML/Graphics.hpp>


class Shape;
struct Message;


#include "Constants.h"
#include "System\Utility.h"
#include "System\String.h"
#include "System\HML.h"
#include "System\Timer.h"

#include "Utility\Vector2D.h"
#include "Utility\Path.h"

#include "System\VideoSettings.h"
#include "System\Input.h"
#include "System\Window.h"

#include "System\Shape\Shape.h"
#include "System\Shape\Rectangle.h"


namespace ait
{
	class Entity;
	class MovingEntity;
	class Vehicle;
	class SteeringBehavior;
	class World;
};

#include "World\Entity.h"
#include "World\MovingEntity.h"
#include "World\Vehicle.h"
#include "World\SteeringBehavior.h"
#include "World\World.h"


const ait::String APP_UID = "AI_Test";



#endif

