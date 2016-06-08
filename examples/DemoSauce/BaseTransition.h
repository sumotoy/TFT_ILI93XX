#ifndef BASE_TRANSITION_H__
#define BASE_TRANSITION_H__

#include <Arduino.h>
#include <TFT_ILI93XX.h>
#include "MathUtil.h"

class BaseTransition {
public:
	BaseTransition(){};

	virtual void init( TFT_ILI93XX tft );
	virtual void restart( TFT_ILI93XX tft, uint_fast16_t color );
	virtual void perFrame( TFT_ILI93XX tft, FrameParams frameParams );
	virtual boolean isComplete();
};

void BaseTransition::init( TFT_ILI93XX tft ) {
	// Extend me
}

void BaseTransition::restart( TFT_ILI93XX tft, uint_fast16_t color ) {
	// Extend me
}

void BaseTransition::perFrame( TFT_ILI93XX tft, FrameParams frameParams ) {
	// Extend me
}

boolean BaseTransition::isComplete() {
	// Extend me
	return false;
}

#endif
