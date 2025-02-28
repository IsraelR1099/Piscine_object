/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Account.hpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: irifarac <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/28 12:56:15 by irifarac          #+#    #+#             */
/*   Updated: 2025/02/28 12:56:16 by irifarac         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

class	Account
{
	private:
		int	m_id;
		int	m_value;
		Account() : m_id(-1), m_value(0) {}
		Account(int id, int value) : m_id(id), m_value(value) {}
		friend class	Bank;
	public:
		void		setId(int id) { m_id = id; }
		void		setValue(int value) { m_value = value; }
		const int	&getId() const { return (m_id); }
		const int	&getValue() const { return (m_value); }
		void		addValue(int value) { m_value += value; }

};
