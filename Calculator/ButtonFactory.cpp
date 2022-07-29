#include "ButtonFactory.h"

 wxButton* ButtonFactory::CreateNumButton(Screen* screen, int num, wxSize& size){
	 return new wxButton(screen, num, std::to_string(num), wxDefaultPosition, size);
 }

 wxButton* ButtonFactory::CreateAddButton(Screen* screen, wxSize& size) {
	 return new wxButton(screen, ID_ADD_BUTTON, "+", wxDefaultPosition, size);
 } 

 wxButton* ButtonFactory::CreateSubButton(Screen* screen, wxSize& size) {
	 return new wxButton(screen, ID_SUB_BUTTON, "-", wxDefaultPosition, size);
 }

 wxButton* ButtonFactory::CreateMultButton(Screen* screen, wxSize& size) {
	 return new wxButton(screen, ID_MUL_BUTTON, "x", wxDefaultPosition, size);
 }

 wxButton* ButtonFactory::CreateDivButton(Screen* screen, wxSize& size) {
	 return new wxButton(screen, ID_DIV_BUTTON, "/", wxDefaultPosition, size);
 }

 wxButton* ButtonFactory::CreateClrButton(Screen* screen, wxSize& size) {
	 return new wxButton(screen, ID_CLR_BUTTON, "C", wxDefaultPosition, size);
 }

 wxButton* ButtonFactory::CreateEqualsButton(Screen* screen, wxSize& size) {
	 return new wxButton(screen, ID_EQUAL_BUTTON, "=", wxDefaultPosition, size);
 }

 wxButton* ButtonFactory::CreateDeciButton(Screen* screen, wxSize& size) {
	 return new wxButton(screen, ID_DECI_BUTTON, ".", wxDefaultPosition, size);
 }

 wxButton* ButtonFactory::CreateSignButton(Screen* screen, wxSize& size) {
	 return new wxButton(screen, ID_SIGN_BUTTON, "+/-", wxDefaultPosition, size);
 }

 wxButton* ButtonFactory::CreateHexButton(Screen* screen, wxSize& size) {
	 return new wxButton(screen, ID_HEX_BUTTON, "HEX", wxDefaultPosition, size);
 }

 wxButton* ButtonFactory::CreateBinButton(Screen* screen, wxSize& size) {
	 return new wxButton(screen, ID_BIN_BUTTON, "BIN", wxDefaultPosition, size);
 }

 wxButton* ButtonFactory::CreateDecButton(Screen* screen, wxSize& size) {
	 return new wxButton(screen, ID_DEC_BUTTON, "DEC", wxDefaultPosition, size);
 }

 wxButton* ButtonFactory::CreateModButton(Screen* screen, wxSize& size) {
	 return new wxButton(screen, ID_MOD_BUTTON, "MOD", wxDefaultPosition, size);
 }

 wxButton* ButtonFactory::CreateSinButton(Screen* screen, wxSize& size) {
	 return new wxButton(screen, ID_SIN_BUTTON, "SIN", wxDefaultPosition, size);
 }

 wxButton* ButtonFactory::CreateCosButton(Screen* screen, wxSize& size) {
	 return new wxButton(screen, ID_COS_BUTTON, "COS", wxDefaultPosition, size);
 }

 wxButton* ButtonFactory::CreateTanButton(Screen* screen, wxSize& size) {
	 return new wxButton(screen, ID_TAN_BUTTON, "TAN", wxDefaultPosition, size);
 }