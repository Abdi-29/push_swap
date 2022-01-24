PREFIX='/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_atof.c                                          :+:    :+:            */
/*                                                     +:+                    */
/*   By: abba <abba@student.codam.nl>                 +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/01/18 18:04:23 by abba          #+#    #+#                 */
/*   Updated: 2022/01/18 18:04:24 by abba          ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */
'

prependHeader() {
    cp "$1" "$1.cp"
    echo "$PREFIX" > "$1"
    cat "$1.cp" >> "$1"
    rm "$1.cp"
}

for file in $(find libft -type f)
do
    prependHeader $file
done