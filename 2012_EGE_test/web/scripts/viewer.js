/* -*- Mode: Java; tab-width: 2; indent-tabs-mode: nil; c-basic-offset: 2 -*- */
/* vim: set shiftwidth=2 tabstop=2 autoindent cindent expandtab: */

  var myCallback = function getPdf(data) {

  var pdf = new PDFJS.PDFDoc(data);
  page = pdf.getPage(paged);
  var scale = 1.2;
  
  var canvas = document.getElementById('the-canvas');
  var context = canvas.getContext('2d');
  canvas.height = page.height * scale;
  canvas.width = page.width * scale;

  page.startRendering(context);

  if(paged==minsh)
  {
  button = document.getElementById('Previous');
  button.disabled = 1;
  }
  else if(paged>minsh)
  {
  button = document.getElementById('Previous');
  button.disabled = 0;
  }
  
  if(paged==maxsh)
  {
  button = document.getElementById('Next');
  button.disabled = 1;
  }
  else if(paged<maxsh)
  {
  button = document.getElementById('Next');
  button.disabled = 0;
  }
};

PDFJS.getPdf('files/inf_ege.pdf', myCallback);
