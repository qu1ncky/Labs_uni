const selectedProducts = [];

const nameInput = document.getElementById("nameInput");
const priceInput = document.getElementById("priceInput");
const addButton = document.getElementById("addButton");

addButton.addEventListener("click", addButtonHandler);

function addToCartHandler() {}

function addToList() {
  const nameTd = document.createElement("td");
  nameTd.innerText = nameInput.value;
  const priceTd = document.createElement("td");
  priceTd.innerText = priceInput.value;

  const tr = document.createElement("tr");
  tr.appendChild(nameTd);
  tr.appendChild(priceTd);
  tr.addEventListener("click", trClickHandler);
  tr.addEventListener("click", (event) => {
    const style = event.target.parentNode.style;
    style.backgroundColor =
      !style.backgroundColor || style.backgroundColor === "white"
        ? "lightblue"
        : "white";
  });
  document.getElementById("listBody").appendChild(tr);
}

function addButtonHandler() {
  if (nameInput.value && priceInput.value > 0) {
    addToList();
    nameInput.value = "";
    priceInput.value = "";
  } else {
    if (!nameInput.value && !priceInput.value) {
      alert("Введите название продукта. Введите цену продукта.");
    }

    if (!nameInput.value && priceInput.value > 0) {
      alert("Введите название продукта");
    }

    if (priceInput.value <= 0 && nameInput.value) {
      alert("Цена должна быть больше чем 0");
    }
  }
}

function trClickHandler(event) {
  const tr = event.target.parentNode;
  const nameTd = document.createElement("td");
  nameTd.innerText = tr.childNodes[0].innerText;
  const priceTd = document.createElement("td");
  priceTd.innerText = tr.childNodes[1].innerText;

  const newTr = document.createElement("tr");
  newTr.addEventListener(
    "mouseover",
    (event) => (event.target.parentNode.style.backgroundColor = "lightgreen")
  );
  newTr.addEventListener(
    "mouseout",
    (event) => (event.target.parentNode.style.backgroundColor = "white")
  );
  newTr.appendChild(nameTd);
  newTr.appendChild(priceTd);

  if (selectedProducts.length === 0) {
    selectedProducts.push({
      name: newTr.childNodes[0].innerText,
      price: newTr.childNodes[1].innerText,
    });
    console.log("123");
    console.log(selectedProducts);
  }
  if (selectedProducts.length > 0) {
    for (let i = 0; i < selectedProducts.length; i++) {
      if (newTr.childNodes[1].innerText !== selectedProducts[i].name) {
        selectedProducts.push({
          name: newTr.childNodes[0].innerText,
          price: newTr.childNodes[1].innerText,
        });
      }
    }
    // selectedProducts.push({name:newTr.childNodes[0].innerText, price:
    // newTr.childNodes[1].innerText})
    console.log("345");
    console.log(selectedProducts);
  }

  //   if (selectedProducts.length > 0){
  //     for (let i = 0; i < selectedProducts.lenght; i++) {
  //       if (newTr.childNodes[0].innerText !== selectedProducts[i].name) {
  //       console.log("123")
  //       selectedProducts.push(newTr)
  //       console.log(selectedProducts)
  //     }
  //   }
  // }
  //   else{
  //     selectedProducts.push({name:newTr.childNodes[0].innerText, price:
  //     newTr.childNodes[1].innerText})

  //     console.log("345")
  //     console.log(selectedProducts)
  //     console.log(selectedProducts[0].name)
  //   }
}
