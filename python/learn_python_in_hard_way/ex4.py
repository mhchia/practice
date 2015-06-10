# -*- coding: utf-8 -*-

cars = 100
space_in_a_car = 4.0
drivers = 30
passengers = 90
cars_not_driven = cars - drivers
cars_driven = drivers
carpool_capacity = cars * space_in_a_car
average_passengers_per_car = passengers / cars_driven

# this can print strings with space within.
print "There are", cars, "cars available."
print "There are only", drivers, "drivers available."
print "There will be", cars_not_driven, "empty cars today."

# but what if we want strings without spaces?
print "%s%s" % (cars, drivers,)
