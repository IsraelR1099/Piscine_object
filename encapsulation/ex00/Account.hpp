#pragma once

class	Account
{
	private:
		int	m_id;
		int	m_value;
	public:
		Account() : m_id(-1), m_value(0) {}
		Account(int id, int value) : m_id(id), m_value(value) {}
		void	setId(int id) { m_id = id; }
		void	setValue(int value) { m_value = value; }
		int		getId() const { return (m_id); }
		int		getValue() const { return (m_value); }

};
