/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   casting_rays.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: haitkadi <haitkadi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/14 21:12:18 by haitkadi          #+#    #+#             */
/*   Updated: 2022/08/14 21:21:46 by haitkadi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d.h"

static void    init_ray_infos(t_ray *ray)
{
    ray->is_facing_down = false;
    ray->is_facing_up = false;
    ray->is_facing_right = false;
    ray->is_facing_left = false;
    if (ray->ray_angle > M_PI && ray->ray_angle < (2 * M_PI))
        ray->is_facing_up = true;
    else
        ray->is_facing_down = true;
    if (ray->ray_angle < (0.5 * M_PI) || ray->ray_angle > (1.5 * M_PI))
        ray->is_facing_right = true;
    else
        ray->is_facing_left = true;
}

/*- - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - */

// static void	draw_fov(t_fcoords start_pos, t_fcoords end_pos, t_img *img)
// {
//     int size;
//     size = (WIN_HEIGHT / 4) / 11;

// 	start_pos.x = ((start_pos.x * size) / CUB_SIZE);
// 	start_pos.y = ((start_pos.y * size) / CUB_SIZE);
//     end_pos.x = ((end_pos.x * size) / CUB_SIZE);
// 	end_pos.y = ((end_pos.y * size) / CUB_SIZE);
// 	draw_line(img, start_pos, end_pos, 0x0000FF);
// }

/*- - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - */

void    casting_rays(t_cub *cub)
{
    t_ray ray;
    int i;

    ft_bzero(&ray, sizeof(t_ray));
    ray.ray_angle = (cub->player.rot - (FOV_ANGLE / 2));
    i = -1;
    while (++i < RAYS_LENGTH)
    {
        ray.ray_angle = normalize_angle(ray.ray_angle);
        init_ray_infos(&ray);
        cast(cub, &ray);
        ray.id = i;
        render_walls(cub, ray);
        ray.ray_angle += (FOV_ANGLE / RAYS_LENGTH);
    }
}
