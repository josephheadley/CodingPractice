module Particle
    attr_accessor :name, :charge, :mass_kg, :mass_eV
    K = 9*10**9
    G = 6.67*10**-11
    p1 = Electron.new("electron", -1.6*10**-19, 9.1*10**-31, 500000)
    p2 = Proton.new("proton", 1.6*10**-19, 1.7*10**-27, 938000000)
    p3 = Neutron.new("neutron", 0, 1.7*10**-27, 950000000)

    def initialize(name, charge, mass_kg, mass_eV)
        @name = name
        @charge = charge
        @mass_kg = mass_kg
        @mass_eV = mass_eV
    end
    def self.interaction1()
        prt1 = gets.chomp  
        case prt1
        when "electron"
            cp1 = p1.charge
            mp1 = p1.mass_kg
        when "proton"
            cp1 = p2.charge
            mp1 = p2.mass_kg
        when "neutron"
            cp1 = p3.charge
            mp1 = p3.mass_kg
        else
            puts "Uh I need you to give me name of one of the particles listed. Please try again."
            self.interaction1()
        end
    end
    def self.interaction2()
        prt2 = gets.chomp  
        case prt2
        when "electron"
            cp2 = p1.charge
            mp2 = p1.mass_kg
        when "proton"
            cp2 = p2.charge
            mp2 = p2.mass_kg
        when "neutron"
            cp2 = p3.charge
            mp2 = p3.mass_kg
        else
            puts "Uh I need you to give me name of one of the particles listed. Please try again."
            self.interaction2()
        end
    end
    def self.coloumb_force(charge1, charge2)
        puts "Please input the distance between the two selected charges"
        distance = gets.chomp.to_i()
        e_force = (K*charge1*charge2)/distance**2
        puts e_force
    end
    def self.gravitational_force(mass1, mass2)
        puts "Please input the distance between the two selected masses"
        distance = gets.chomp.to_i()
        g_force = (G*mass1*mass2)/distance**2
        puts g_force
    end
end

class Electron
    include Particle
    def to_s
        "The #{@name} is a negatively charged particle of #{@charge} volts with a mass of #{@mass_kg} kilograms (or #{@mass_eV} electron volts)."
    end
end
class Proton
    include Particle
    def to_s
        "The #{@name} is a positively charged particle of #{@charge} volts with a mass of #{@mass_kg} kilograms (or #{@mass_eV} electron volts)."
    end
end
class Neutron
    include Particle
    def to_s
        "The #{@name} is neutrally charged particle of #{@charge} volts with a mass of #{@mass_kg} kilograms (or #{@mass_eV} electron volts)."
    end
end

print "\n"
puts p1
print "\n"
puts p2
print "\n"
puts p3
print "\n"
puts "So what interactions between what two particle do you want to know about?"
Particle.interaction1()
Particle.interaction2()
Particle.coloumb_force(cp1, cp2)
Particle.gravitational_force(mp1, mp2)