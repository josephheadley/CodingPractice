K = 9*10**9
G = 6.67*10**-11
require "ostruct"
Electron = OpenStruct.new(name:"electron", charge:-1.6*10**-19, mass_kg:9.1*10**-31, mass_eV:500000)
Proton = OpenStruct.new(name:"proton", charge:1.6*10**-19, mass_kg:1.7*10**-27, mass_eV:938000000)
Neutron = OpenStruct.new(name:"neutron", charge:0, mass_kg:1.7*10**-27, mass_eV:939000000)

puts "Please input the distance between the two selected particles."
distance = gets.chomp.to_i()
eforce = lambda {puts (K*Electron.charge*Proton.charge)/distance**2}
#eforce = ->() {puts (G*Electron.charge*Proton.charge)/distance**2}
gforce = lambda {puts (G*Electron.mass_kg*Proton.mass_kg)/distance**2}

puts "This is the amount of electrical force exerted between a proton and an electron at a distance of #{distance} meters:"
eforce.call
puts "This is the amount of gravitational force exerted between a proton and an electron at a distance of #{distance} meters:"
gforce.call