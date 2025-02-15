/**
 * @file checker.hpp
 */
#ifndef CHECKER_HPP
#define CHECKER_HPP
#include "common.hpp"
#include "systemc.hpp"
#include "tlm.hpp"
struct Checker_module : sc_core::sc_module
{
  Checker_module( sc_core::sc_module_name instance ); 
  ~Checker_module( void ) = default;
  // Ports
  sc_core::sc_fifo_in<RawData_t>  rawin_port  { "rawin_port"  };
  sc_core::sc_in<FixedPt_t>       result_port { "result_port" };
private:
  // Local channels
  tlm::tlm_fifo<FixedPt_t>        expect_fifo { "expect_fifo", -2 };
  tlm::tlm_fifo<FixedPt_t>        result_fifo { "result_fifo", -2 };
  // Attributes
  bool                            anticipate_reset ;
  size_t                          verified_count   ;
  size_t                          mismatches       ;
  // Processes and overrides
  void received_method( void );
  void checker_thread( void );
  void end_of_simulation( void ) override;
};
#endif/*CHECKER_HPP*/
