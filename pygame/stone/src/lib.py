# Copyright (c) 2024 Oliver Tzeng. All Rights Reserved.
# created: 2024/03/06 13/38

from screeninfo import get_monitors

width = get_monitors()[0].width
height = get_monitors()[0].height
caption = "stone"
fps = 60
color = "white"

def compare(a, b, c):
	return (a < b and b < c)
def collision(obj, sub):
	pos_obj = obj.rect.topleft
	height_obj = obj.rect.height
	width_obj = obj.rect.width
	pos_sub = sub.rect.topleft
	height_sub = sub.rect.height
	width_sub = sub.rect.width

	if (compare(0, pos_obj[1] - pos_sub[1], height_sub) or pos_obj[1] - pos_sub[1] == height_sub or not (pos_obj[1] - height_obj) or compare(0, pos_obj[1] + height_obj - pos_sub[1], height_sub)):
		if (compare(0, pos_obj[0] - pos_sub[0], width_sub) or pos_obj[0] - pos_sub[0] == width_sub or not (pos_obj[0] - width_obj) or compare(0, pos_obj[0] + width_obj - pos_sub[0], width_sub)):
			return True
	
	return False
