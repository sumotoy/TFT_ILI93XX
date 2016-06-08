#ifndef BASE_ANIMATION_H__
#define BASE_ANIMATION_H__

#include <Arduino.h>
#include <TFT_ILI93XX.h>
#include "MathUtil.h"

class BaseAnimation {
public:
	BaseAnimation(){};

	virtual void init( TFT_ILI93XX tft );
	virtual uint_fast16_t bgColor( void );
	virtual void reset( TFT_ILI93XX tft );
	virtual String title();

	virtual boolean willForceTransition( void );
	virtual boolean forceTransitionNow( void );

	virtual void perFrame( TFT_ILI93XX tft, FrameParams frameParams );
};

void BaseAnimation::init( TFT_ILI93XX tft ) {
	// Extend me
}

uint_fast16_t BaseAnimation::bgColor( void ) {
	// Extend me
	return RED;	// Everyone loves magenta
}

void BaseAnimation::reset( TFT_ILI93XX tft ) {
	// Extend me
}

String BaseAnimation::title() {
	return "BaseAnimation";
}

boolean BaseAnimation::willForceTransition( void ) {
	return false;	// Default: SuperTFT will transition animations automatically
}

boolean BaseAnimation::forceTransitionNow( void ) {
	// Extend me
	return false;	// Default: SuperTFT will transition animations automatically
}

void BaseAnimation::perFrame( TFT_ILI93XX tft, FrameParams frameParams ) {
	// Extend me
}

#endif
