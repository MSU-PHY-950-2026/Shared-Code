void customMC(void){}

Energy distributions & crises
==> Energy usage per household, could be as specific as per person
  ==> Geography dependence
  ==> Consumer type (business vs person, type of energy user, number of household members)
  ==> Regional dependence in past usage, model as Gaussian?
  ==> Time dependence
  
==> Annual variations in energy use
  ==> Extreme weather dependence
  ==> Temperature
  ==> Household climate control
  ==> Population changes vs season

==> Variations in energy supply
  ==> War? External vs internal sources, Modeling previous conflicts
  ==> Natural disasters & delivery disruptions
  ==> Natural reservoirs & availability
  ==> External resource availibility, export/import model

==> Reliability of various energy sources
  ==> Availability & cost of various sources (seasonal variance)
  ==> Duration of resource availibility/viability
  ==> Deferred maintenance
  
==> Energy transport cost & reliability
  ==> Urban vs rural vs suburban distribution?
  ==> Development level of infrastructure
  ==> Delivery mechanism
  
==> Availability of personpower/workforce

==> Political climate & governance structure
  ==> Government subsidies
  ==> Restrictions on energy use
  ==> Country GDP
  ==> External sanctions & embargos

  
Sales advertising vs revenue, interest rates
Insurance cost vs benefit




  
Yellowstone wolves, prey species
==> Wolf and prey populations
  ==> Time evolution for population & composition
  ==> seeding population
  ==> limits to population from external factors
  ==> health of populations
  
==> Population diversity
  ==> Seasonal variation & migratory behavior
  ==> Availability of diverse food sources
  
==> Natural lifetimes of animals
==> Rate of predation, per animal type
==> Weather & climate impact, natural disasters
  
==> Animal birth rates
==> Food & habitat availability
==> Habitat & population density
  ==> Urban vs rural vs no human habitats
  
==> rate of disease, fatal and survivable, transmission rates
  ==> number of impacted individuals
  
==> Food consumption vs age
==> Human factors
==> Hunting efficiency
  ==> Within species competition
  ==> Population health
==> Competition from other species
==> Adaptation & evolution


  

  Goal: Predict wolf and prey population N years beyond initial conditions

  Global assumptions:
  ==> Isolated habitat with no human interactions
  ==> Restricted habitat area, forcing variable density
  ==> Modeling averages over single year periods (time step = 1 year)
  ==> No animal migration
  
  Input:
  ==> Initial wolf population, assume equal male/female?  Ages?
  ==> Prey population, within limited species (rabbits, deer, moose, ??).
  ==> Animal reproduction rate: 2->N average per year (2->N is a bit arbitrary).  Does this depend on density?
  ==> Wolf predation rate per species (depends on population density?)
  ==> Habitat size (determines densities)
  ==> Weather adversity index (separately for wolves and prey)
  ==> Disease advertity index (separately for wolves and prey)
  ==> Average animal lifetimes

  Model details/assumptions:
  ==> Require relationships between preditor and prey densities vs predation rate
  ==> Require relationship between prey density and food competition?
      ==> And also weather adversity?
      ==> Or assume general abundance?
  ==> No dependence of predation rate on age?
  ==> Require relationship between weather adversity and animal death rate
  ==> Require relationship between disease adversity and animal death rate
  ==> Require list of animal attributes & their population distribution
  ==> Require means to pass down traits to offspring (eg, hunting skill or reproduction rate)
  ==> Require model for prey density vs preditor survival rate


  Model implementation:
  ==> Define class for a given animal,
      ==> Decorate with required variables to track animal attributes
  ==> Generate arrays of each species type, populated according to initial conditions
  ==> Iterate one year time steps
      ==> Calculate animal densities
      ==> Determine death events, remove dead animals from arrays (dead animals don't reproduce)
      ==> Determine birth events, adding new animals with new attributes drawn from parents
      ==> Repeat until desired future year
