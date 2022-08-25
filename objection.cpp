/**
 * @file   objection.hpp
 * @brief  Stop SystemC simulation when the last objection is removed.
 */
#include "objection.hpp"
#include <systemc>
#include <string>
#include <set>

size_t Objection::created = 0;
std::set<std::string> Objection::objections = {};

Objection::Objection( const std::string& name ) ///< Create an objection
  : m_name( name )
{
    created = 0u;
    sc_assert( name.size() > 0 );
    auto elt = objections.find( m_name );
    if( elt == objections.end() )
        objections.insert( m_name );
    std::string note{ "Raising objection " };
    note += m_name;
    SC_REPORT_INFO_VERB( MSGID, note.c_str(), sc_core::SC_DEBUG );
    ++created;
}

Objection::~Objection() ///< Remove an objection
{
    auto elt = objections.find( m_name );
    sc_assert( elt != objections.end() );
    objections.erase( elt );
    if( objections.empty() and sc_core::sc_is_running() ) 
    {
        sc_core::sc_spawn( [&]()
        {
        sc_core::wait( sc_core::SC_ZERO_TIME );
        if( objections.empty() ) {
            std::string note{ "Shutting down " };
            note += m_name;
            SC_REPORT_INFO_VERB( MSGID, note.c_str(), sc_core::SC_NONE );
            sc_core::sc_stop();
        }
        });
    } else {
        std::string note{ "Removing objection " };
        note += m_name;
        SC_REPORT_INFO_VERB( MSGID, note.c_str(), sc_core::SC_DEBUG );
    }
}

///< Return total times used
size_t Objection::total() { 
    return Objection::created; 
} 

///< Return the outstanding objections
size_t Objection::count() { 
    return Objection::objections.size(); 
} 
