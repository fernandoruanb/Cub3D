#Name of the program or the library

NAME = cub3d

#Compilers and flags

CC = cc
CFLAGS = -g3 -Wall -Werror -Wextra
MLXFLAGS = -L $(MLXDIR) -lmlx -lXext -lX11 -lm

#Directories

SRCDIR = srcs
INCDIR = includes
MLXDIR = minilibx-linux
LIBFT_DIR = libft

# LIBFT

LIBFT = $(LIBFT_DIR)/libft.a

#SRCS

SRCS =  $(SRCDIR)/cub3d/main.c\
	$(SRCDIR)/validation/check_cub.c\
	$(SRCDIR)/init_game/init_game.c\
	$(SRCDIR)/init_game/get_map.c\
	$(SRCDIR)/the_cub_3d_powered/get_tex_colour.c\
	$(SRCDIR)/free_game/free_game.c\
	$(SRCDIR)/init_game/init_all_things.c\
	$(SRCDIR)/init_game/get_map_textures.c\
	$(SRCDIR)/utils/show_map.c\
	$(SRCDIR)/init_game/get_no_texture.c\
	$(SRCDIR)/init_game/get_so_texture.c\
	$(SRCDIR)/init_game/get_we_texture.c\
	$(SRCDIR)/init_game/get_ea_texture.c\
	$(SRCDIR)/init_game/get_floor_colours.c\
	$(SRCDIR)/init_game/get_ceiling_colours.c\
	$(SRCDIR)/init_game/get_true_map.c\
	$(SRCDIR)/utils/show_textures.c\
	$(SRCDIR)/validation/is_valid_map.c\
	$(SRCDIR)/validation/is_anything_null.c\
	$(SRCDIR)/validation/check_colours.c\
	$(SRCDIR)/validation/check_true_map.c\
	$(SRCDIR)/validation/check_is_valid_xpm.c\
	$(SRCDIR)/validation/check_elements.c\
	$(SRCDIR)/validation/get_all_lines.c\
	$(SRCDIR)/validation/check_entire_wall.c\
	$(SRCDIR)/validation/check_first_last_wall.c\
	$(SRCDIR)/validation/check_invalid_access.c\
	$(SRCDIR)/validation/flood_fill.c\
	$(SRCDIR)/utils/drawstr.c\
	$(SRCDIR)/set_window/set_window.c\
	$(SRCDIR)/set_window/run_window.c\
	$(SRCDIR)/validation/check_security_on_map.c\
	$(SRCDIR)/validation/check_is_anything_equal.c\
	$(SRCDIR)/validation/check_repeat_textures.c\
	$(SRCDIR)/validation/check_split_length.c\
	$(SRCDIR)/utils/free_dynamic_texture.c\
	$(SRCDIR)/validation/remove_spaces_and_tabs.c\
	$(SRCDIR)/init_game/get_width_heigth.c\
	$(SRCDIR)/init_game/rgb_to_rrggbb.c\
	$(SRCDIR)/bonus/minimap.c\
	$(SRCDIR)/utils/get_t_game.c\
	$(SRCDIR)/ray_cast/init_map.c\
	$(SRCDIR)/bonus/draw_radius.c\
	$(SRCDIR)/bonus/update_angle_dir_x_y.c\
	$(SRCDIR)/bonus/draw_fov.c\
	$(SRCDIR)/bonus/get_distance.c\
	$(SRCDIR)/init_game/check_and_set_images.c\
	$(SRCDIR)/the_cub_3d_powered/init_all_3d.c\
	$(SRCDIR)/the_cub_3d_powered/render_the_3d.c\
	$(SRCDIR)/the_cub_3d_powered/draw_floor.c\
	$(SRCDIR)/the_cub_3d_powered/draw_ceiling.c\
	$(SRCDIR)/ray_cast/can_move.c\
	$(SRCDIR)/ray_cast/get_plane_x_y.c\
	$(SRCDIR)/ray_cast/movements.c\
	$(SRCDIR)/set_window/get_keys.c\
	$(SRCDIR)/dda/calculate_perp_dist_update_wall.c\
	$(SRCDIR)/dda/dda_loop.c\
	$(SRCDIR)/dda/init_camera_plane.c\
	$(SRCDIR)/dda/init_dda_params.c\
	$(SRCDIR)/set_window/mouse.c\
	$(SRCDIR)/dda/init_ray.c\
	$(SRCDIR)/cub3d/destroy.c\
	$(SRCDIR)/utils/get_sign.c\
	$(SRCDIR)/utils/fps_control.c\
	$(SRCDIR)/validation/find_another.c\
	$(SRCDIR)/init_game/find_texture.c

#OBJS

OBJS =  $(SRCS:.c=.o)

#Main

all: $(NAME)

#All the magic happens here

$(NAME): $(OBJS)
	@$(MAKE) -C $(LIBFT_DIR) --no-print-directory
	@$(MAKE) -C $(MLXDIR) --no-print-directory
	@$(CC) $(CFLAGS) -I $(INCDIR) -I $(MLXDIR) -o $(NAME) $(OBJS) $(MLXFLAGS) $(LIBFT)

# .c -> .o

%.o:%.c
	@echo "\033[38;5;208mCompiling	->	$<\033[0m"
	@$(CC) $(CFLAGS) -I $(INCDIR) -c $< -o $@

#clean

clean:
	@echo "\033[1;32m===========================================\033[0m"
	@echo "\033[1;32m		OBJECTS REMOVED						\033[0m"
	@echo "\033[1;32m===========================================\033[0m"
	@rm -rf $(OBJS)
	@$(MAKE) -C $(LIBFT_DIR) clean --no-print-directory

run: all
	valgrind --show-leak-kinds=all --leak-check=full ./cub3d maps/test_map4.cub

#fclean

fclean: clean
	@echo "\033[1;32m===========================================\033[0m"
	@echo "\033[1;32m		$(NAME) REMOVED						\033[0m"
	@echo "\033[1;32m===========================================\033[0m"
	@rm -rf $(NAME)
	@$(MAKE) -C $(LIBFT_DIR) fclean --no-print-directory

#restart

re: fclean all

.PHONY: all fclean clean re
