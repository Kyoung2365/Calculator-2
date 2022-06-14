#include "ButtonFactory.h"

 ButtonFactory* ButtonFactory::CreateButton(Buttons id) {
	 return new ButtonFactory(id);
 }

 