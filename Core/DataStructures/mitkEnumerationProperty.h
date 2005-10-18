#ifndef _MITK_ENUMERATION_PROPERTY__H_
#define _MITK_ENUMERATION_PROPERTY__H_

#include "mitkBaseProperty.h"
#include <map>
#include <string>

namespace mitk
{

/**
 * This class may be used to store properties similar to enumeration values.
 * Each enumeration value is identified via a string representation and a
 * id. Note, that both string representation and id MUST be unique. This is checked
 * when inserting a new enumeration value. Please note that you have to add valid
 * enumeration values before you may use the Get/SetValue methods.
 */
class EnumerationProperty : public BaseProperty
{
public:

  mitkClassMacro( EnumerationProperty, BaseProperty );

  /**
   * Represents the unique id which is asigned to each enumeration value
   */
  typedef unsigned int IdType;

  /**
   * Type used to store a mapping from enumeration id to enumeration string/
   * description
   */
  typedef std::map<IdType, std::string> EnumIdsContainerType;

  /**
   * Type used to store a mapping from enumeration string/description to 
   * enumeration id
   * 
   */
  typedef std::map<std::string, IdType> EnumStringsContainerType;

  /**
   * Type used for iterators over all defined enumeration values.
   */
  typedef EnumStringsContainerType::const_iterator EnumConstIterator;

  /**
   * Default constructor. The current value of the enumeration is undefined.
   */
  EnumerationProperty();

  /**
   * Adds an enumeration value into the enumeration. The name and id provided
   * must be unique. This is checked while adding the new enumeration value.
   * If it is not unique, false is returned. If addition was successful, true
   * is returned.
   * @param name the unique string representation of the enumeration value
   * @param id the unique integer representation of the enumeration value
   * @returns true, if the name/id combination was successfully added to the
   * enumeration values or true otherwise
   */
  virtual bool AddEnum( const std::string& name, const IdType& id );

  /**
   * Sets the current value of the enumeration
   * @param name the string representation of the enumeration value to set
   * @returns true if the value was successfully set (i.e. it was valid), or 
   * false, if the name provided is incalid.
   */
  virtual bool SetValue( const std::string& name );

  /**
   * Sets the current value of the enumeration
   * @param id the integer representation of the enumeration value to set
   * @returns true if the value was successfully set (i.e. it was valid), or 
   * false, if the id provided is invalid.
   */
  virtual bool SetValue( const IdType& id );

  /**
   * Returns the id of the current enumeration value. If it was not yet set,
   * the return value is unspecified
   */
  virtual IdType GetValueAsId() const;

  /**
   * Returns the string representation of the current enumeration value. If it 
   * was not yet set, the return value is unspecified
   */
  virtual std::string GetValueAsString() const;

  /**
   * Clears all possible enumeration values and the current enumeration value.
   */
  virtual void Clear();

  /**
   * Determines the number of enumeration values which have been added via 
   * AddEnum(...).
   * @returns the number of enumeration values associated with this Enumeration
   * Property
   */
  virtual unsigned int Size() const;

  /**
   * Provides access to the set of known enumeration values. The string representation
   * may be accessed via iterator->first, the id may be access via iterator->second
   * @returns an iterator over all enumeration values.
   */
  virtual EnumConstIterator Begin() const;

  /**
   * Specifies the end of the range of the known enumeration values.
   * @returns an iterator pointing past the last known element of the possible
   * enumeration values.
   */
  virtual EnumConstIterator End() const;

  /**
   * Returns the string representation for the given id.
   * @param id the id for which the string representation should be determined
   *        if id is invalid, the return value is unspecified.
   * @returns the string representation of the given enumeration value
   */
  virtual std::string GetEnumString( const IdType& id ) const;

  /**
   * Returns the integer representation for the given string.
   * @param name the enumeration name for which the integer representation should be determined
   *        if the name is invalid, the return value is unspecified.
   * @returns the integer representation of the given enumeration value
   */
  virtual IdType GetEnumId( const std::string& name ) const;

  /**
   * Determines if a given integer representation of an enumeration value
   * is valid or not
   * @param val the integer value to check
   * @returns true if the given value is valid or false otherwise
   */
  virtual bool IsValidEnumerationValue( const IdType& val ) const;

  /**
   * Determines if a given string representation of an enumeration value
   * is valid or not
   * @param val the string to check
   * @returns true if the given value is valid or false otherwise
   */
  virtual bool IsValidEnumerationValue( const std::string& val ) const;

  virtual bool operator==( const BaseProperty& property ) const;

protected:

  IdType m_CurrentValue;

  EnumIdsContainerType m_EnumIds;

  EnumStringsContainerType m_EnumStrings;

};


}


#endif
