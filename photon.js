const photonUrl = "https://api.particle.io/v1/devices/3b002a000f47353136383631/led?access_token=525ee521b709fe0627f29ac4a41271876d313f1e";

let antSpeciesCount = {
  california: "293",
  oregon: "110",
  washington: "104",
  nevada: "208",
  utah: "225",
  arizona: "341",
  idaho: "139"
}

const returnValues = (state) =>{
  switch(state){
    case "california":
      return antSpeciesCount.california;
    case "oregon":
      return antSpeciesCount.oregon;
    case "washington":
      return antSpeciesCount.washington;
    case "nevada":
      return antSpeciesCount.nevada;
    case "utah":
      return antSpeciesCount.utah;
    case "arizona":
      return antSpeciesCount.arizona;
    case "idaho":
      return antSpeciesCount.idaho;
  }
}

$('#photonForm').on('submit', (e)=>{
  e.preventDefault();
  let state = $('.state').val();

  let data = {
    n: returnValues(state)
  }
  $.ajax({
    url: photonUrl,
    method: 'POST',
    data: data,
    success: (response)=>{
      console.log(response);
    }
  });
});
