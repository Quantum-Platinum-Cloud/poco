//
// Control.h
//
// $Id: //poco/Main/WebWidgets/include/Poco/WebWidgets/Control.h#7 $
//
// Library: WebWidgets
// Package: Controls
// Module:  Control
//
// Definition of the Control class.
//
// Copyright (c) 2008, Applied Informatics Software Engineering GmbH.
// and Contributors.
//
// Permission is hereby granted, free of charge, to any person or organization
// obtaining a copy of the software and accompanying documentation covered by
// this license (the "Software") to use, reproduce, display, distribute,
// execute, and transmit the Software, and to prepare derivative works of the
// Software, and to permit third-parties to whom the Software is furnished to
// do so, all subject to the following:
// 
// The copyright notices in the Software and this entire statement, including
// the above license grant, this restriction and the following disclaimer,
// must be included in all copies of the Software, in whole or in part, and
// all derivative works of the Software, unless such copies or derivative
// works are solely in the form of machine-executable object code generated by
// a source language processor.
// 
// THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
// IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
// FITNESS FOR A PARTICULAR PURPOSE, TITLE AND NON-INFRINGEMENT. IN NO EVENT
// SHALL THE COPYRIGHT HOLDERS OR ANYONE DISTRIBUTING THE SOFTWARE BE LIABLE
// FOR ANY DAMAGES OR OTHER LIABILITY, WHETHER IN CONTRACT, TORT OR OTHERWISE,
// ARISING FROM, OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER
// DEALINGS IN THE SOFTWARE.
//


#ifndef WebWidgets_Control_INCLUDED
#define WebWidgets_Control_INCLUDED


#include "Poco/WebWidgets/View.h"
#include "Poco/WebWidgets/Cell.h"


namespace Poco {
namespace WebWidgets {


class WebWidgets_API Control: public View
	/// Control is the base class for all visual objects reacting to user input 
	/// and, optionally, managing cells. Subclasses of Control provide events 
	/// and, in a Model-View-Controller pattern, implement the View role.
{
public:
	typedef Poco::AutoPtr<Control> Ptr;
		
	void enable(bool enabled = true);
		/// Enables (if enabled == true) or disables the Control.
		
	void disable();
		/// Disables the Control.
		
	bool isEnabled() const;
		/// Returns true iff the Control is enabled.
	
	template <class C>
	typename C::Ptr cell() const
		/// Returns the Control's Cell, or null if the Control has no
		/// or more than one cells.
	{
		return _pCell.cast<C>();
	}

	Cell::Ptr getCell() const;
		/// Returns the Cell

	void setValue(const Poco::Any& value);
		/// Sets the value for this Control's Cell.
		///
		/// The actual type of the value must match the type
		/// expected by the Cell or its Formatter.
		
	const Poco::Any& getValue() const;
		/// Returns the value for this Control's Cell.
		
	void setString(const std::string& value);	
		/// Sets the value for this Control's Cell to the given string.
		
	std::string getString() const;
		/// Returns the value of this Control's Cell formatted as a string.
		///
		/// Throws a BadCastException if the Cell's value is not a string and
		/// no formatter has been set.
		
	void setInt(int value);
		/// Sets the value of this Control's Cell to the given int value.
		
	int getInt() const;
		/// Returns the value of this Control's Cell as an int value.
		///
		/// Throws a BadCastException if the Cell's value is not an int.

	void setDouble(double value);
		/// Sets the value of this Control's Cell to the given double value.
		
	double getDouble() const;
		/// Returns the value of this Control's Cell as a double value.
		///
		/// Throws a BadCastException if the Cell's value is not a double.

	void setBool(bool value);
		/// Sets the value of this Control's Cell to the given bool value.
		
	bool getBool() const;
		/// Returns the value of this Control's Cell as a bool value.
		///
		/// Throws a BadCastException if the Cell's value is not a bool.

	void setFormatter(Formatter::Ptr pFormatter);
		/// Sets the Formatter for this Control's Cell.
		
	Formatter::Ptr getFormatter() const;
		/// Returns the Formatter for this Control's Cell.

	void setEditable(bool editable = true);
		/// Sets whether the Cell's contents can be edited.

	bool isEditable() const;
		/// Returns true iff the Cell is editable.


	// View
	void setText(const std::string& text);
	std::string getText() const;
	void setToolTip(const std::string& text);
	std::string getToolTip() const;

	// Renderable
	void renderHead(const RenderContext& context, std::ostream& str) const;
	void renderBody(const RenderContext& context, std::ostream& str) const;
		
protected:
	Control(const std::string& name, const std::type_info& type);
		/// Creates a Control and assigns it the given name.
		
	Control(const std::type_info& type);
		/// Creates a Control.
		
	~Control();
		/// Destroys the Control.
		
	void setCell(Cell::Ptr pCell);
		/// Sets the Control's Cell.

private:
	Cell::Ptr _pCell;
};


//
// inlines
//
inline void Control::setCell(Cell::Ptr pCell)
{
	_pCell = pCell;
}


inline Cell::Ptr Control::getCell() const
{
	return _pCell;
}


inline void Control::setValue(const Poco::Any& value)
{
	_pCell->setValue(value);
}


inline const Poco::Any& Control::getValue() const
{
	return _pCell->getValue();
}


inline void Control::setString(const std::string& value)
{
	_pCell->setString(value);
}


inline std::string Control::getString() const
{
	return _pCell->getString();
}


inline void Control::setInt(int value)
{
	_pCell->setInt(value);
}


inline int Control::getInt() const
{
	return _pCell->getInt();
}


inline void Control::setDouble(double value)
{
	_pCell->setDouble(value);
}


inline double Control::getDouble() const
{
	return _pCell->getDouble();
}


inline void Control::setBool(bool value)
{
	_pCell->setBool(value);
}


inline bool Control::getBool() const
{
	return _pCell->getBool();
}


inline void Control::setFormatter(Formatter::Ptr pFormatter)
{
	_pCell->setFormatter(pFormatter);
}


inline Formatter::Ptr Control::getFormatter() const
{
	return _pCell->getFormatter();
}


} } // namespace Poco::WebWidgets


#endif // WebWidgets_Control_INCLUDED