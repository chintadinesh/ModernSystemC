/**
 * @file   objection.hpp
 * @brief  Stop SystemC simulation when the last objection is removed.
 */
#ifndef OBJECTION_HPP
#define OBJECTION_HPP
#include <systemc>
#include <string>
#include <set>
class Objection
{
    public:
        Objection( const std::string& name ); ///< Create an objection
        ~Objection(); ///< Remove an objection
        size_t total(); ///< Return total times used
        size_t count(); ///< Return the outstanding objections
    private:
        std::string m_name;
        // Static stuff
        static constexpr const char* const  MSGID { "/Doulos/Objection"};
        static size_t                created;
        static std::set<std::string> objections;
};
#endif/*OBJECTION_HPP*/
