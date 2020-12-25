K = 9*10**9
G = 6.67*10**-11
require "ostruct"
Electron = OpenStruct.new(name:"electron", charge:-1.6*10**-19, mass_kg:9.1*10**-31, mass_eV:500000)
#Electron = Struct.new(:name, :charge, :mass_kg, :mass_eV)
Proton = OpenStruct.new(name:"proton", charge:1.6*10**-19, mass_kg:1.7*10**-27, mass_eV:938000000)
Neutron = OpenStruct.new(name:"neutron", charge:0, mass_kg:1.7*10**-27, mass_eV:939000000)

eforce = Proc.new do |distance|
    puts "So the distance between these particles is #{distance} meters?"
    print "\n"
    puts "This is the amount of electrical force exerted between these particles:"
    puts (K*Electron.charge*Proton.charge)/distance**2
end
gforce = Proc.new do |distance|
    puts "So the distance between these particles is #{distance} meters?"
    print "\n"
    puts "This is the amount of gravitational force exerted between these particles:"
    puts (G*Electron.mass_kg*Proton.mass_kg)/distance**2
end

#eforce.call(4)
#gforce.call(4)

def calc(proc)
    start = Time.now
    proc.call(4)
    dur = Time.now - start
end

puts calc(eforce)
puts calc(gforce)