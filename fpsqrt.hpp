/**
 * @file fpsqrt.hpp
 *
 * Computing the square root of an integer or a fixed point into a 
 * fixed point integer. A fixed point is a 32 bit value with the comma between
 * the bits 15 and 16, where bit 0 is the less significant bit of the value. 
 * 
 * The algorithms can be easily extended to 64bit integers, or different 
 * fixed point comma positions. 
 * 
 * Algorithm and code Author: Christophe Meessen 1993. 
 * Initially published in: usenet comp.lang.c, Thu, 28 Jan 1993 08:35:23 GMT, 
 * Subject: Fixed point sqrt ; by Meessen Christophe
 */
#ifndef FSQRT_HPP
#define FSQRT_HPP
#include "common.hpp"
#include <systemc>
struct FP {

/**
 * FixedPt_t fpsqrt( FixedPt_t v );
 *
 * Compute FixedPt_t to FixedPt_t square root
 * RETURNS the FixedPt_t point square root of v (FixedPt_t)
 * REQUIRES v is positive
 */

static FixedPt_t fpsqrt ( FixedPt_t X );

};
#endif/*FSQRT_HPP*/

